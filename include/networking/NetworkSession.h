#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		class NetworkSession : public Singularity::Object
		{
			DECLARE_OBJECT_TYPE;

			private:
				#pragma region Static Variables
				static unsigned g_iReferences;
				#pragma endregion

				#pragma region Variables
				UUID		m_kNetworkId;

				bool		m_bConnected;
				bool		m_bAutoFlush;

				IPAddress	m_pHost;
				unsigned	m_pPort;

				ADDRINFO	m_kMulticastAddr;
				ADDRINFO	m_kLocalAddr;
				SOCKET		m_kSocket;

				unsigned	m_iReceiveBufferSize;
				char*		m_pReceiveBuffer;

				unsigned	m_iSendBufferSize;
				unsigned	m_iSendBufferOffset;
				char*		m_pSendBuffer;
				#pragma endregion

				#pragma region Methods
				bool CreateSocket(ADDRINFO& addressInfo);
				bool JoinMulticast(ADDRINFO& addressInfo);
				bool DropMulticast(ADDRINFO& addressInfo);
				void SendKeepAlive();
				#pragma endregion

			protected:
				#pragma region Constructors and Finalizers
				NetworkSession(const unsigned receiveBufferSize = 4096, const unsigned sendBufferSize = 4096);
				#pragma endregion

				#pragma region Methods
				virtual void Connect(IPAddress host, unsigned port);
				virtual void Disconnect();
				void Flush();

				void Update();
				#pragma endregion

				#pragma region Event Methods
				virtual void OnBeginUpdate() { };
				virtual void OnProcessPacket(Packet* packet);
				virtual void OnEndUpdate() { };
				#pragma endregion
			
			public:
				#pragma region Constructors and Finalizers
				~NetworkSession();
				#pragma endregion

				#pragma region Properties
				inline const UUID Get_NetworkId() const { return this->m_kNetworkId; };

				inline const bool Get_IsConnected() const { return this->m_bConnected; };

				inline IPAddress Get_Host() const { return this->m_pHost; };

				inline const unsigned Get_Port() const { return this->m_pPort; };

				inline const int Get_ReceiveBufferSize() const { return this->m_iReceiveBufferSize; };
				void Set_ReceiveBufferSize(const unsigned value);

				inline const int Get_SendBufferSize() const { return this->m_iSendBufferSize; };
				void Set_SendBufferSize(const unsigned value);

				inline const bool Get_AutoFlush() const { return this->m_bAutoFlush; };
				inline void Set_AutoFlush(const bool value) { this->m_bAutoFlush = value; };
				#pragma endregion

				#pragma region Methods
				void SendPacket(Packet* packet);
				#pragma endregion

				#pragma region Events
				DelegateHandler ProcessPacket;
				#pragma endregion

				friend class NetworkTask;
		};
	}
}