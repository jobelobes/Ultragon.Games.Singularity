#include "audio\Singularity.Audio.h"

/*
* AdaptiveEnvironment.h
*
* An adaptive environment that fits everything together.
*
* Author: Sela Davis
*
* Created: May 05, 2010 (05/05/10)
* Last modified: May 05, 2010 (05/05/10)
*/

namespace Singularity
{
	namespace Audio
	{

		class AdaptiveEnvironment
		{
			private:
			
			#pragma region Variables
				
				String m_pName;
				DynamicList<AdaptiveSlice*> m_pSlices;
				DynamicList<AdaptiveParameter*> m_pParameters;
				DynamicList<string> m_pCategories;
				bool m_bPlaying;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveEnvironment(String name);

				// Destructor.
				~AdaptiveEnvironment();

			#pragma endregion

			#pragma region Methods

				DynamicList<Cue*> DetermineCuesToPlay();
				AdaptiveSlice* ChooseSlice(String category, float bpm, Vector2 timesig, String rhythm, String keysig);
				void LoadEnvironmentFromXml(String path);

				void AddSlice(AdaptiveSlice* slice);
				void AddParameter(AdaptiveParameter* param);

				void AddCategory(String category);

				void SetVariable(String variable, float value);

				String GetName();

			#pragma endregion
		};
	}
}