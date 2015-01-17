#include "triggerHappy\TriggerHappy.h"
 
using namespace Singularity;
using namespace Singularity::Threading;
using namespace Singularity::Components;
using namespace Singularity::Animations;
using namespace Singularity::Inputs;
using namespace Singularity::Graphics;
using namespace Singularity::Content;
using namespace Singularity::Audio;
using namespace Singularity::Gui;
using namespace Singularity::Physics;
using namespace Singularity::Scripting;
using namespace Singularity::Particles;
 
class TriggerHappy : public Game
{
	public:
		#pragma region Constructors and Finalizers
		TriggerHappy() : Game() {};
		~TriggerHappy() {};
		#pragma endregion
 
		#pragma region Overriden Methods
		void BeginRun()
		{
			int max = 256;
			GameObject** obj = new GameObject*[max];
			for(int j = 0; j < 100; j++)
			{
				printf("Creating Gameobject\n");
				for(int i = 0; i < max; i++)
				{
					obj[i] = GameObject::Create();
					obj[i]->AddComponent(new Animation());
					obj[i]->AddComponent(new GuiScreen());
					obj[i]->AddComponent(new BoxCollider());
				}

				printf("Destroying Gameobject\n");
				for(int i = 0; i < max; i++)
					obj[i]->Destroy();
			}
		};
		#pragma endregion
};
 
int main(int argc, char* argv[])
{
	try
	{
		boost::shared_ptr<TriggerHappy> game(new TriggerHappy());
		game->Run();
	}
	catch(SingularityException& e) 
	{
		fprintf(stderr, "An exception has occurred: %s\n", boost::diagnostic_information(e));
 
		system("PAUSE"); // press any key to continue...
	}
 
	return 0;
}