#include "networking\Singularity.Networking.h"

using namespace Singularity::Components;

namespace Singularity
{
	namespace Networking
	{
		IMPLEMENT_OBJECT_TYPE(Singularity.Networking, NetworkSession, Object);

		#pragma region Static Variables
		unsigned NetworkSession::g_iReferences = 0;
		#pragma endregion

		#pragma region Properties
		void NetworkSession::Set_ReceiveBufferSize(const unsigned value)
		{
			this->m_iReceiveBufferSize = value;

			if(this->m_pReceiveBuffer != NULL)
				free(this->m_pReceiveBuffer);

			this->m_pReceiveBuffer = (char*)malloc(this->m_iReceiveBufferSize);
		}

		void NetworkSession::Set_SendBufferSize(const unsigned value)
		{
			this->m_iSendBufferSize = value;
			this->m_iSendBufferOffset = 0;

			if(this->m_pSendBuffer != NULL)
				free(this->m_pSendBuffer);
			
			this->m_pSendBuffer = (char*)malloc(this->m_iSendBufferSize);
		}
		#pragma endregion

		#pragma region Constructors and Finalizers
		NetworkSession::NetworkSession(const unsigned receiveBufferSize, const unsigned sendBufferSize)
			: m_kSocket(INVALID_SOCKET), m_pReceiveBuffer(NULL), m_pSendBuffer(NULL), 
			  m_iReceiveBufferSize(receiveBufferSize), m_iSendBufferSize(sendBufferSize),
			  m_iSendBufferOffset(0)
		{ 
			if(++NetworkSession::g_iReferences == 1)
			{
				WSADATA wsaData;
				if (::WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
					throw SingularityException("Unable to start winsock system.");

				if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0 )
				{
					::WSACleanup();
					throw SingularityException("Unable to start winsock system.");
				}
			}

			UuidCreate(&this->m_kNetworkId);

			this->m_pReceiveBuffer = (char*)malloc(this->m_iReceiveBufferSize);
			this->m_pSendBuffer = (char*)malloc(this->m_iSendBufferSize);
		}

		NetworkSession::~NetworkSession()
		{
			if(this->m_bConnected)
				this->Disconnect();

			free(this->m_pReceiveBuffer);
			free(this->m_pSendBuffer);

			if(--NetworkSession::g_iReferences == 0)
				::WSACleanup();
		}
		#pragma endregion

		#pragma region Methods
		bool NetworkSession::CreateSocket(ADDRINFO& addressInfo)
		{
			// Create a SOCKET for connecting to server
			this->m_kSocket = socket(addressInfo.ai_family, addressInfo.ai_socktype, 0);
			if (this->m_kSocket == INVALID_SOCKET)
				return false;

			DWORD nonblock = 1;
			if (ioctlsocket(this->m_kSocket, FIONBIO, &nonblock) == SOCKET_ERROR)
				  return false;

			// Set TTL of multicast packet
			DWORD ttl = 7;
			if (setsockopt(this->m_kSocket, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&ttl, sizeof(ttl)) != 0 )
				return false;

			return true;
		}

		bool NetworkSession::JoinMulticast(ADDRINFO& addressInfo)
		{
			struct ip_mreq mRequest;
			unsigned reuseAddr;

			/* Specify the multicast group */
			memcpy(&mRequest.imr_multiaddr, &((sockaddr_in*)addressInfo.ai_addr)->sin_addr, sizeof(mRequest.imr_multiaddr));

			/* Accept multicast from any interface */
			mRequest.imr_interface.s_addr = htonl(INADDR_ANY);

			/* Join the multicast address */
			if (setsockopt(this->m_kSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mRequest, sizeof(mRequest)) != 0 )
				return false;

			reuseAddr = 1;
			if (setsockopt(this->m_kSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuseAddr, sizeof(reuseAddr)) != 0 )
				return false;
			
			return true;
		}

		bool NetworkSession::DropMulticast(ADDRINFO& addressInfo)
		{
			ip_mreq mRequest;

			/* Specify the multicast group */
			memcpy(&mRequest.imr_multiaddr, &((sockaddr_in*)addressInfo.ai_addr)->sin_addr, sizeof(mRequest.imr_multiaddr));

			/* Accept multicast from any interface */
			mRequest.imr_interface.s_addr = htonl(INADDR_ANY);

			if(setsockopt(this->m_kSocket, IPPROTO_IP, IP_DROP_MEMBERSHIP,(char*)&mRequest, sizeof(mRequest)))
				return false;
			return true;
		}

		void NetworkSession::SendKeepAlive()
		{
			Packet* packet = (Packet*)(this->m_pSendBuffer + this->m_iSendBufferOffset);
			packet->Index = 0;
			packet->From = this->m_kNetworkId;
			packet->Type = 0;
			packet->Command = 0;
			packet->DataLength = 0;
			packet->Data = 0;

			this->m_iSendBufferOffset += sizeof(Packet);
		}

		void NetworkSession::Update()
		{
			Packet* packet;
			int offset, length;

			this->OnBeginUpdate();

			do
			{
				offset = 0;
				length = recv(this->m_kSocket, this->m_pReceiveBuffer, this->m_iReceiveBufferSize, 0);
				while(offset < length && offset >= 0) // >= 0 fixes some nasty insta-crash bug we had show up. total show-stopper.
				{
					packet = (Packet*)(this->m_pReceiveBuffer + offset);
					if(packet->DataLength > 0)
						this->OnProcessPacket(packet);

					offset += packet->DataLength + sizeof(Packet) - 1;
				}

				memset(this->m_pReceiveBuffer, 0, this->m_iReceiveBufferSize);
			}
			while(length > 0);

			this->Flush(); // send out any lingering packets to the great beyond.

			this->OnEndUpdate();
		}

		void NetworkSession::Connect(IPAddress host, unsigned port)
		{
			int err;
			char portStr[6];
			ADDRINFO *multicastAddr, *localAddr;
			// Resolve the multicast group address
			ADDRINFO hints = { 0 };
			hints.ai_family = PF_UNSPEC;
			hints.ai_socktype = SOCK_DGRAM;
			hints.ai_flags = AI_NUMERICHOST;

			_itoa_s(port, &portStr[0], 6, 10);

			if (getaddrinfo(host.ToString().c_str(), portStr, &hints, &multicastAddr) != 0 )
				throw SingularityException("Network Error: Error resolving addresses.", WSAGetLastError());

			// Get a local address with the same family as our multicast group
			hints.ai_family   = multicastAddr->ai_family;
			hints.ai_socktype = SOCK_DGRAM;
			hints.ai_flags    = AI_PASSIVE;
			if (getaddrinfo(NULL, portStr, &hints, &localAddr) != 0 )
				throw SingularityException("Network Error: Error resolving addresses.", WSAGetLastError());
			
			this->CreateSocket(*multicastAddr);
			if(this->m_kSocket == INVALID_SOCKET)
				throw SingularityException("Network Error: No socket available for use.");

			this->JoinMulticast(*multicastAddr);

			// bind to the multicast port
			if (bind(this->m_kSocket, localAddr->ai_addr, localAddr->ai_addrlen) != 0 )
			{
				err = WSAGetLastError();
				throw SingularityException("Network Error: Failed to bind to local device.", err);
			}
			memcpy(&this->m_kMulticastAddr, multicastAddr, sizeof(ADDRINFO));
			memcpy(&this->m_kLocalAddr, localAddr, sizeof(ADDRINFO));

			this->m_pHost = host;
			this->m_pPort = port;
		}

		void NetworkSession::Disconnect()
		{
			this->Flush();
			this->DropMulticast(this->m_kMulticastAddr);
			closesocket(this->m_kSocket);
		}

		void NetworkSession::Flush()
		{
			if(this->m_iSendBufferOffset == 0)
				this->SendKeepAlive();

			int result = sendto(this->m_kSocket, this->m_pSendBuffer, this->m_iSendBufferOffset, 0, this->m_kMulticastAddr.ai_addr, this->m_kMulticastAddr.ai_addrlen);
			if (result == SOCKET_ERROR)
				throw SingularityException("Network Error: Unable to flush Send buffer.", WSAGetLastError());
			
			this->m_iSendBufferOffset = 0;
		}

		void NetworkSession::SendPacket(Packet* packet)
		{
			unsigned size = packet->DataLength + sizeof(Packet) - 1;
			if((this->m_iSendBufferOffset + size) >= this->m_iSendBufferSize)
			{
				if(!this->m_bAutoFlush)
					throw SingularityException("Send buffer has been filled, unable to send packet.");
				this->Flush();
			}

			packet->From = this->Get_NetworkId();
			memcpy(this->m_pSendBuffer + this->m_iSendBufferOffset, packet, size);
			this->m_iSendBufferOffset += size;
		}

		void NetworkSession::OnProcessPacket(Packet* packet)
		{
			for(unsigned i = 0; i < this->ProcessPacket.Count(); ++i)
//				if(this->ProcessPacket[i]->GetType().Equals(NetworkDelegate::Type))
					((NetworkDelegate*)this->ProcessPacket[i])->Invoke(packet);
		}
		#pragma endregion
	}
}