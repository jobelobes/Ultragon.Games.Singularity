#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		class Network : public Singularity::Networking::NetworkSession
		{
			private:
				#pragma region Static Variables
				static Network*				g_pInstance;
				#pragma endregion

				#pragma region Variables
				Timer						m_kTimer;

				unsigned					m_iPlayerCount;
				NetworkPlayer				m_pPlayers[SINGULARITY_NETWORK_MAX_CLIENTS];
				float						m_pPlayersLastUpdate[SINGULARITY_NETWORK_MAX_CLIENTS];
				NetworkPlayer				m_kCurrentPlayer;


				unsigned					m_iGameCount;
				NetworkGameDescription		m_pGames[SINGULARITY_NETWORK_MAX_GAMES];
				float						m_pGamesLastUpdate[SINGULARITY_NETWORK_MAX_CLIENTS];
				NetworkGame*				m_pCurrentGame;
				#pragma endregion

				#pragma region Constructors and Finalizers
				Network() : NetworkSession(), m_iPlayerCount(0), m_iGameCount(0), m_pCurrentGame(NULL) { };
				#pragma endregion

				#pragma region Methods
				void RegisterPlayer(NetworkPlayer& player);
				void UnregisterPlayer(NetworkPlayer& player);
				void UpdatePlayer(NetworkPlayer& player);
				void GetPlayerList();
				
				void RegisterGame(NetworkGameDescription& game);
				void UnregisterGame(NetworkGameDescription& game);
				void UpdateGame(NetworkGameDescription& game);
				void GetGameList();
				#pragma endregion

			protected:
				#pragma region Overriden Methods
				void Connect(IPAddress host, unsigned port);

				void OnBeginUpdate();
				void OnProcessPacket(Packet* packet);
				void OnEndUpdate();
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~Network() { };
				#pragma endregion

				#pragma region Static Methods

				static void Set_CurrentPlayerName(String name);
				static void Set_CurrentPlayerId(int id);

				static NetworkPlayer& CurrentPlayer();
				static NetworkGame* CurrentGame();

				static Network* ConnectTo(IPAddress host, unsigned port);

				static NetworkGame* CreateGame(String name);
				static void LeaveGame();
				static NetworkGame* JoinGame(const NetworkGameDescription& game);
				static NetworkGameDescription* FindGames(unsigned& count);
				#pragma endregion

				friend class NetworkTask;
		};
	}
}