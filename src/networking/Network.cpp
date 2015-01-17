#include "networking\Singularity.Networking.h"

using namespace Singularity::Components;

#define PACKER_TYPE_LOBBY 0x20

#define PACKER_COMMAND_REGISTER 0x10
#define PACKER_COMMAND_UNREGISTER 0x20
#define PACKER_COMMAND_UPDATE 0x40
#define PACKER_COMMAND_LIST 0x80

#define PACKER_COMMAND_PLAYER 0x01
#define PACKER_COMMAND_GAME 0x02

namespace Singularity
{
	namespace Networking
	{
		#pragma region Static Variables
		Network* Network::g_pInstance = NULL;
		#pragma endregion

		#pragma region Methods
		void Network::RegisterPlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_REGISTER | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
		}

		void Network::UnregisterPlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_UNREGISTER | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
		}

		void Network::UpdatePlayer(NetworkPlayer& player)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkPlayer));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_UPDATE | PACKER_COMMAND_PLAYER;
			packet->DataLength = sizeof(NetworkPlayer);
			memcpy(&packet->Data, &player, sizeof(NetworkPlayer));
			this->SendPacket(packet);
		}

		void Network::GetPlayerList()
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_LIST | PACKER_COMMAND_PLAYER;
			packet->DataLength = 1;
			packet->Data = NULL;
			this->SendPacket(packet);
		}
		
		void Network::RegisterGame(NetworkGameDescription& game)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkGameDescription));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_REGISTER | PACKER_COMMAND_GAME;
			packet->DataLength = sizeof(NetworkGameDescription);
			memcpy(&packet->Data, &game, sizeof(NetworkGameDescription));
			this->SendPacket(packet);
		}

		void Network::UnregisterGame(NetworkGameDescription& game)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkGameDescription));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_UNREGISTER | PACKER_COMMAND_GAME;
			packet->DataLength = sizeof(NetworkGameDescription);
			memcpy(&packet->Data, &game, sizeof(NetworkGameDescription));
			this->SendPacket(packet);
		}

		void Network::UpdateGame(NetworkGameDescription& game)
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet) + sizeof(NetworkGameDescription));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_UPDATE | PACKER_COMMAND_GAME;
			packet->DataLength = sizeof(NetworkGameDescription);
			memcpy(&packet->Data, &game, sizeof(NetworkGameDescription));
			this->SendPacket(packet);
		}

		void Network::GetGameList()
		{
			Packet* packet = (Packet*)malloc(sizeof(Packet));
			packet->Index = 0;
			packet->Type = PACKER_TYPE_LOBBY;
			packet->Command = PACKER_COMMAND_LIST | PACKER_COMMAND_GAME;
			packet->DataLength = 1;
			packet->Data = NULL;
			this->SendPacket(packet);
		}

		void Network::Connect(IPAddress host, unsigned port)
		{
			NetworkSession::Connect(host, port);
			
			this->m_kCurrentPlayer.Id = this->Get_NetworkId();
			this->m_kCurrentPlayer.Lag = 0.0f;
			this->m_kCurrentPlayer.Name[0] = '\0';
			this->m_kCurrentPlayer.PlayerId = -1;
			this->RegisterPlayer(this->m_kCurrentPlayer);

			this->GetPlayerList();
			this->GetGameList();

			this->m_kTimer.Reset();
		}

		void Network::OnBeginUpdate()
		{
			if(this->m_kTimer.Get_ElapsedTime() > 5.0f)
			{
				this->m_kTimer.Tick();

				this->GetPlayerList();
				this->GetGameList();
			}
		}

		void Network::OnProcessPacket(Packet* packet)
		{
			if(packet->Type != PACKER_TYPE_LOBBY)
				return;

			switch(packet->Command)
			{
				case PACKER_COMMAND_REGISTER | PACKER_COMMAND_PLAYER:
					{
						NetworkPlayer* player = &this->m_pPlayers[this->m_iPlayerCount++];
						memcpy(player, &packet->Data, sizeof(NetworkPlayer));
						break;
					}
				case PACKER_COMMAND_REGISTER | PACKER_COMMAND_GAME:
					{
						NetworkGameDescription* game = &this->m_pGames[this->m_iGameCount++];
						memcpy(game, &packet->Data, sizeof(NetworkGameDescription));
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
				case PACKER_COMMAND_UPDATE | PACKER_COMMAND_GAME:
					{
						NetworkGameDescription* game = (NetworkGameDescription*)&packet->Data;
						for(unsigned i = 0; i < this->m_iGameCount; ++i)
						{
							if(memcmp(&game->Id, &this->m_pGames[i].Id, sizeof(UUID)) == 0)
							{
								memcpy(&this->m_pGames[i], &packet->Data, sizeof(NetworkGameDescription));
								this->m_pGamesLastUpdate[i] = this->m_kTimer.Get_TotalTime();
								return;
							}
						}

						this->m_pGamesLastUpdate[this->m_iGameCount] = this->m_kTimer.Get_TotalTime();
						game = &this->m_pGames[this->m_iGameCount++];
						memcpy(game, &packet->Data, sizeof(NetworkGameDescription));
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
				case PACKER_COMMAND_UNREGISTER | PACKER_COMMAND_GAME:
					{
						NetworkGameDescription* game = (NetworkGameDescription*)&packet->Data;
						for(unsigned i = 0; i < this->m_iGameCount; ++i)
						{
							if(memcmp(&game->Id, &this->m_pGames[i].Id, sizeof(UUID)) == 0)
							{
								memcpy(&this->m_pGames[i], &this->m_pGames[--this->m_iGameCount], sizeof(NetworkGameDescription));
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
							if(memcmp(&this->m_pPlayers[i].Id, &this->Get_NetworkId(), sizeof(UUID)) == 0)
							{
								this->UpdatePlayer(this->m_pPlayers[i]);
								return;
							}
						}
					}
				case PACKER_COMMAND_LIST | PACKER_COMMAND_GAME:
					{
						if(memcmp(&packet->From, &this->Get_NetworkId(), sizeof(UUID)) == 0)
							return;

						this->m_kTimer.Tick(); // no need in flooding the network with list requests

						for(unsigned i = 0; i < this->m_iGameCount; ++i)
						{
							if(memcmp(&this->m_pGames[i].Owner.Id, &this->Get_NetworkId(), sizeof(UUID)) == 0)
							{
								this->UpdateGame(this->m_pGames[i]);
								return;
							}
						}
					}
				default:
					NetworkSession::OnProcessPacket(packet);
					break;
			}
		}	

		void Network::OnEndUpdate()
		{
			float totalTime = this->m_kTimer.Get_TotalTime();
			if(totalTime < 60.0f)
				return;

			totalTime -= 60.0f;
			for(unsigned i = 0; i < this->m_iPlayerCount; ++i)
			{
				if(this->m_pPlayersLastUpdate[i] < totalTime && memcmp(&this->m_pPlayers[i].Id, &this->Get_NetworkId(), sizeof(UUID)) != 0)
				{
					memcpy(&this->m_pPlayersLastUpdate[i], &this->m_pPlayersLastUpdate[--this->m_iPlayerCount], sizeof(float));
					memcpy(&this->m_pPlayers[i], &this->m_pPlayers[this->m_iPlayerCount], sizeof(NetworkPlayer));
				}
			}

			for(unsigned i = 0; i < this->m_iGameCount; ++i)
			{
				if(this->m_pGamesLastUpdate[i] < totalTime && memcmp(&this->m_pGames[i].Owner.Id, &this->Get_NetworkId(), sizeof(UUID)) != 0)
				{
					memcpy(&this->m_pGamesLastUpdate[i], &this->m_pGamesLastUpdate[--this->m_iGameCount], sizeof(float));
					memcpy(&this->m_pGames[i], &this->m_pGames[this->m_iGameCount], sizeof(NetworkGameDescription));
				}
			}
		}
		#pragma endregion

		#pragma region Static Methods
		Network* Network::ConnectTo(IPAddress host, unsigned port)
		{
			if(!Network::g_pInstance)
				Network::g_pInstance = new Network();
			else if(Network::g_pInstance->Get_IsConnected())
				Network::g_pInstance->Disconnect();

			Network::g_pInstance->Connect(host, port);
			return Network::g_pInstance; 
		}

		void Network::Set_CurrentPlayerName(String name)
		{
			//Network::g_pInstance->m_kCurrentPlayer.Name = name.c_str();
			strcpy_s(&Network::g_pInstance->m_kCurrentPlayer.Name[0], name.size() + 1, name.c_str()); // +1 to account for '\0' in c_str
			Network::g_pInstance->m_pCurrentGame->UpdatePlayer(Network::g_pInstance->m_kCurrentPlayer);
		}

		void Network::Set_CurrentPlayerId(int id)
		{
			Network::g_pInstance->m_kCurrentPlayer.PlayerId = id;
			Network::g_pInstance->m_pCurrentGame->UpdatePlayer(Network::g_pInstance->m_kCurrentPlayer);
		}

		NetworkPlayer& Network::CurrentPlayer()
		{
			return Network::g_pInstance->m_kCurrentPlayer;
		}

		NetworkGame* Network::CurrentGame()
		{
			return Network::g_pInstance->m_pCurrentGame;
		}

		NetworkGame* Network::CreateGame(String name)
		{
			if(Network::g_pInstance->m_pCurrentGame != NULL)
				return Network::g_pInstance->m_pCurrentGame;

			IPAddress host = Network::g_pInstance->Get_Host();
			NetworkGameDescription game;
			UuidCreate(&game.Id);
			strcpy_s(&game.Name[0], name.size() + 1, name.c_str()); // +1 to account for '\0' in c_str
			game.CurrentParticipants = 1;
			game.Endpoint = IPAddress(host.GetAddressByte(0), host.GetAddressByte(1), host.GetAddressByte(2) + 1, host.GetAddressByte(3));
			game.Port = Network::g_pInstance->Get_Port();
			memcpy(&game.Owner, &Network::g_pInstance->m_kCurrentPlayer, sizeof(NetworkPlayer));
			game.MaxParticipants = SINGULARITY_NETWORK_MAX_PARTICIPANTS;
			game.Lag = 0.1f;
			Network::g_pInstance->RegisterGame(game);

			Network::g_pInstance->m_pCurrentGame = new NetworkGame(game, true);
			Network::g_pInstance->m_pCurrentGame->RegisterPlayer(game.Owner);
			return Network::g_pInstance->m_pCurrentGame;
		}

		void Network::LeaveGame()
		{
			NetworkPlayer player;
			player.Id = Network::g_pInstance->Get_NetworkId();
			player.Lag = 0.0f;
			player.Name[0] = '\0';

			Network::g_pInstance->m_pCurrentGame->UnregisterPlayer(player);
			Network::g_pInstance->m_pCurrentGame->Disconnect();
			Network::g_pInstance->m_pCurrentGame = NULL;
		}

		NetworkGame* Network::JoinGame(const NetworkGameDescription& game)
		{
			NetworkPlayer player;
			player.Id = Network::g_pInstance->Get_NetworkId();
			player.Lag = 0.0f;
			player.Name[0] = '\0';

			Network::g_pInstance->m_pCurrentGame = new NetworkGame(game, false);
			Network::g_pInstance->m_pCurrentGame->RegisterPlayer(player);
			return Network::g_pInstance->m_pCurrentGame;
		}

		NetworkGameDescription* Network::FindGames(unsigned& count)
		{
			count = Network::g_pInstance->m_iGameCount;
			return &Network::g_pInstance->m_pGames[0];
		}
		#pragma endregion
	}
}