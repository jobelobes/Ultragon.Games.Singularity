#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

		AdaptiveSlice::AdaptiveSlice(String name, String category, String rhythm, String keysig, Vector2 timesig, float bpm, string cueName, float importance) : m_pName(name), m_pCategory(category), m_pRhythm(rhythm), m_pKeysig(keysig), m_sTimesig(timesig), m_fBpm(bpm), m_fImportance(importance), m_pCue(NULL), m_fChance(0.0f)
			{
//				m_pCue = AudioManager::Instantiate()->CreateCue(cueName);
			}

			AdaptiveSlice::~AdaptiveSlice()
			{
			}

		#pragma endregion

		#pragma region Methods

			float AdaptiveSlice::CalculateProbability()
			{
	
		        float retval = 1.0f;
			    float importanceTotal = 0.0f;

				// there's got to be a better way to do this, but...
				//foreach (AdaptiveProperty prop in m_properties.Values)
				for (DynamicList<AdaptiveProperty*>::iterator iter = m_pProperties.begin(); iter != m_pProperties.end(); iter++)
		        {
					importanceTotal += (*iter)->GetImportance();
			    }

	            //foreach (AdaptiveProperty prop in m_properties.Values)
				// ugh, I hate to do this again, but I need the total FIRST.
				for (DynamicList<AdaptiveProperty*>::iterator iter = m_pProperties.begin(); iter != m_pProperties.end(); iter++)
		        {
					retval *= (((*iter)->GetValueAtPoint((*iter)->GetParent()->GetCurrentValue()) * (*iter)->GetImportance()) / importanceTotal);
				}

				return retval;
			}

			void AdaptiveSlice::AddProperty(AdaptiveProperty* prop)
			{
				m_pProperties.push_back(prop);
			}

			void AdaptiveSlice::RemoveProperty(AdaptiveProperty* prop)
			{
				unsigned count, index;
				count = this->m_pProperties.size();
				for(index = 0; index < count; ++index)
				{
					if(this->m_pProperties[index] == prop)
					{
						this->m_pProperties[index] = this->m_pProperties[count - 1];
						this->m_pProperties.pop_back();
					}
				}
			}

			void AdaptiveSlice::PlayCue()
			{
				m_pCue->PlayCue();
			}

			AdaptiveProperty* AdaptiveSlice::GetProperty(string name)
			{
				for (DynamicList<AdaptiveProperty*>::iterator iter = m_pProperties.begin(); iter != m_pProperties.end(); iter++)
				{
					if ((*iter)->GetName() == name)
						return *iter;
				}
				return NULL; // :/
			}

			DynamicList<AdaptiveProperty*> AdaptiveSlice::GetAllProperties()
			{
				return m_pProperties;
			}

			String AdaptiveSlice::GetCategory()
			{
				return m_pCategory;
			}

			String AdaptiveSlice::GetRhythm()
			{
				return m_pRhythm;
			}

			String AdaptiveSlice::GetKeySig()
			{
				return m_pKeysig;
			}

			Vector2 AdaptiveSlice::GetTimeSig()
			{
				return m_sTimesig;
			}

			float AdaptiveSlice::GetBPM()
			{
				return m_fBpm;
			}

			String AdaptiveSlice::GetName()
			{
				return m_pName;
			}

			float AdaptiveSlice::GetImportance()
			{
				return m_fImportance;
			}

			float AdaptiveSlice::GetChance()
			{
				return m_fChance;
			}

			void AdaptiveSlice::SetChance(float chance)
			{
				m_fChance = chance;
			}

			Cue* AdaptiveSlice::GetCue()
			{
				return m_pCue;
			}

			void AdaptiveSlice::SetBPM(float bpm)
			{
				this->m_fBpm = bpm;
			}

			void AdaptiveSlice::SetCategory(String category)
			{
				this->m_pCategory = category;
			}

			void AdaptiveSlice::SetRhythm(String rhythm)
			{
				this->m_pRhythm = rhythm;
			}

			void AdaptiveSlice::SetKeySig(String keysig)
			{
				this->m_pKeysig = keysig;
			}

			void AdaptiveSlice::SetTimeSig(Vector2 timesig)
			{
				this->m_sTimesig = timesig;
			}

			void AdaptiveSlice::SetName(String name)
			{
				m_pName = name;
			}

			void AdaptiveSlice::SetImportance(float importance)
			{
				m_fImportance = importance;
			}

			void AdaptiveSlice::SetCue(Cue* cue)
			{
				m_pCue = cue;
			}
			
		#pragma endregion
	}
}