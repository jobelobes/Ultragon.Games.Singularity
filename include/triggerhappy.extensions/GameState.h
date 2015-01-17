//All structs that are going to be passed over the network


struct GameState
{
	int MatchType;
	int PlayerCount;
	PlayerState*
	int TeamScore*;

};

struct PlayerState
{
	int TeamID;
	int PlayerID;
	int Health;
	int Score;
	int State;		//0 = alive, 1 = respawn


}

struct WeaponState
{
	
};

struct ModifierState
{
	int type;
};