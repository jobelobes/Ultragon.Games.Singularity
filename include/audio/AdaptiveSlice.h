#include "audio\Singularity.Audio.h"

/*
* AdaptiveSlice.h
*
* A short adaptive cue with metadata.
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
		class AdaptiveSlice
		{
			private:
			
			#pragma region Variables
				
				String m_pName;
				String m_pCategory;
				String m_pRhythm;
				String m_pKeysig;
				Vector2 m_sTimesig;
				float m_fBpm;
				Cue* m_pCue;
				float m_fImportance;
				float m_fChance;
				DynamicList<AdaptiveProperty*> m_pProperties;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveSlice(String name, String category, String rhythm, String keysig, Vector2 timesig, float bpm, string cueName, float importance);

				// Destructor.
				~AdaptiveSlice();

			#pragma endregion

			#pragma region Methods

				float CalculateProbability();
				void AddProperty(AdaptiveProperty* prop);
				void RemoveProperty(AdaptiveProperty* prop);
				void PlayCue();


				// after we've loaded this in, we have NO need to change its properties. that's only necessary in the generator.
				AdaptiveProperty* GetProperty(string name);
				DynamicList<AdaptiveProperty*> GetAllProperties();
				String GetCategory();
				void SetCategory(String category);
				String GetRhythm();
				void SetRhythm(String rhythm);
				String GetKeySig();
				void SetKeySig(String keysig);
				Vector2 GetTimeSig();
				void SetTimeSig(Vector2 timesig);
				float GetBPM();
				void SetBPM(float bpm);
				String GetName();
				void SetName(String name);
				float GetImportance();
				void SetImportance(float importance);
				float GetChance();
				void SetChance(float chance);
				Cue* GetCue();
				void SetCue(Cue*);
				

			#pragma endregion
		};
	}
}