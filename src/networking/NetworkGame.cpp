#include "networking\Singularity.Networking.h"

#define PACKER_TYPE_GAME 0x30

#define PACKER_COMMAND_REGISTER 0x10
#define PACKER_COMMAND_UNREGISTER 0x20
#define PACKER_COMMAND_UPDATE 0x40
#define PACKER_COMMAND_LIST 0x80

#define PACKER_COMMAND_PLAYER 0x01
#define PACKER_COMMAND_DATA 0x04

using namespace Singularity::Components;

namespace Singularity
{
	namespace Networking
	{
		#pragma region Constructors and Finalizers
		NetworkGame::NetworkGame(NetworkGameDescription description, bool isHost) 
			: m_bIsHost(isHost), m_iPlayerCount(0), m_kDescription(description)
		{
			this->Connect(description.Endpoint, description.Port);
		}
		#pragma endregion

		#pragma region Methods
		void NetworkGame::RegisterPlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_GAME;
			packet->Command = PACKER_COMMAND_REGISTER | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
			if(!this->m_bIsHost)
				this->GetPlayerList();
		}

		void NetworkGame::UnregisterPlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_GAME;
			packet->Command = PACKER_COMMAND_UNREGISTER | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
		}

		void NetworkGame::UpdatePlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_GAME;
			packet->Command = PACKER_COMMAND_UPDATE | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
		}

		void NetworkGame::GetPlayerList()
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_GAME;
			packet->Command = PACKER_COMMAND_LIST | PACKER_COMMAND_PLAYER;
			packet->DataLength = 1;
			packet->Data = NULL;
			this->SendPacket(packet);
		}

		void NetworkGame::ResetReady()
		{

		}

		void NetworkGame::Start()
		{

		}

		void NetworkGame::Destroy()
		{

		}

		NetworkPlayer* NetworkGame::GetPlayers(unsigned& count)
		{
			count = this->m_iPlayerCount;
			return &this->m_pPlayers[0];
		}
		#pragma endregion

		#pragma region Overriden Methods
		void NetworkGame::OnProcessPacket(Packet* packet)
		{
			if(packet->Type != PACKER_TYPE_GAME)
				return;

			switch(packet->Command)
			{
				case PACKER_COMMAND_REGISTER | PACKER_COMMAND_PLAYER:
					{
						NetworkPlayer* player = &this->m_pPlayers[this->m_iPlayerCount++];
						memcpy(player, &packet->Data, sizeof(NetworkPlayer));
						break;
					}
				case PACKER_COMMAND_UPDATE | PACKER_COMMAND_PLAYER:
					{
						NetworkPlayer* player = (NetworkPlayer*)&packet->Data;
						for(unsigned i = 0; i < this->m_iPlayerCount; ++i)
						{
							if(memcmp(&player->Id, &this->m_pPlayers[i].Id, sizeof(UUID)) == 0)
							{
								memcpy(&this->m_pPlayers[i], &packet->Data, sizeof(NetworkPlayer));
								this->m_pPlayersLastUpdate[i] = this->m_kTimer.Get_TotalTime();
								return;
							}
						}

						this->m_pPlayersLastUpdate[this->m_iPlayerCount] = this->m_kTimer.Get_TotalTime();
						player = &this->m_pPlayers[this->m_iPlayerCount++];
						memcpy(player, &packet->Data, sizeof(NetworkPlayer));
						break;
					}
				case PACKER_COMMAND_UNREGISTER | PACKER_COMMAND_PLAYER:
					{
						NetworkPlayer* player = (NetworkPlayer*)&packet->Data;
						for(unsigned i = 0; i < this->m_iPlayerCount; ++i)
						{
							if(memcmp(&player->Id, &this->m_pPlayers[i].Id, sizeof(UUID)) == 0)
							{
								memcpy(&this->m_pPlayers[i], &this->m_pPlayers[--this->m_iPlayerCount], sizeof(NetworkPlayer));
								return;
							}
						}

						break;
					}
				case PACKER_COMMAND_LIST | PACKER_COMMAND_PLAYER:
					{
						if(memcmp(&packet->From, &this->Get_NetworkId(), sizeof(UUID)) == 0)
							return;

						this->m_kTimer.Tick(); // no need in flooding the network with list requests

						for(unsigned i = 0; i < this->m_iPlayerCount; ++i)
						{
							if(memcmp(&this->m_pPlayers[i].Id, &this->Get_NetworkId(), sizeof(UUID)) != 0)
							{
								this->UpdatePlayer(this->m_pPlayers[i]);
								return;
							}
						}
					}
				default:
					NetworkSession::OnProcessPacket(packet);
					break;
			}
		}
		#pragma endregion
	}
}