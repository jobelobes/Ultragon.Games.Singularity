#include "networking\Singularity.Networking.h"

namespace Singularity
{
	namespace Networking
	{
		struct NetworkGameDescription
		{
			UUID			Id;
			char			Name[256];
			NetworkPlayer	Owner;
			IPAddress		Endpoint;
			unsigned		Port;
			unsigned		MaxParticipants;
			unsigned		CurrentParticipants;
			float			Lag;
		};

		class NetworkGame : public Singularity::Networking::NetworkSession
		{
			private:
				#pragma region Variables
				Timer						m_kTimer;
				bool						m_bIsHost;
				NetworkGameDescription		m_kDescription;

				unsigned					m_iPlayerCount;
				NetworkPlayer				m_pPlayers[SINGULARITY_NETWORK_MAX_PARTICIPANTS];
				float						m_pPlayersLastUpdate[SINGULARITY_NETWORK_MAX_CLIENTS];
				#pragma endregion

				#pragma region Constructors and Finalizers
				NetworkGame(NetworkGameDescription description, bool isHost);
				#pragma endregion

				#pragma region Methods
				void RegisterPlayer(NetworkPlayer& player);
				void UnregisterPlayer(NetworkPlayer& player);
				void UpdatePlayer(NetworkPlayer& player);
				void GetPlayerList();
				#pragma endregion

			protected:
				#pragma region Methods
				void OnProcessPacket(Packet* packet);
				#pragma endregion

			public:
				#pragma region Constructors and Finalizers
				~NetworkGame() { };
				#pragma endregion

				#pragma region Properties
				inline const bool Get_IsHost() const { return this->m_bIsHost; }
				#pragma endregion

				#pragma region Methods
				void ResetReady();
				void Start();
				void Destroy();

				NetworkPlayer* GetPlayers(unsigned& count);
				#pragma endregion

				friend class Network;
		};
	}
}