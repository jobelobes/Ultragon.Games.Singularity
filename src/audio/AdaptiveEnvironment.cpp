#include "audio\Singularity.Audio.h"
#include <fstream>

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

			AdaptiveEnvironment::AdaptiveEnvironment(String name) : m_pName(name), m_bPlaying(false)
			{
				this->LoadEnvironmentFromXml("..\\newtest.xml");
			}

			AdaptiveEnvironment::~AdaptiveEnvironment()
			{

			}

			DynamicList<Cue*> AdaptiveEnvironment::DetermineCuesToPlay()
			{
				float bpm = 0.0f;
				Vector2 timesig = Vector2(0,0);
				String rhythm = "";
				String keysig = "";
				DynamicList<Cue*> cues;
	            
				// this should all happen in the AdaptiveMusicManager, which will handle playback
				//this->m_pCues.clear()

				AdaptiveSlice* slice = NULL;

				//foreach (string s in m_categories)
				for (DynamicList<string>::iterator iter = m_pCategories.begin(); iter != m_pCategories.end(); iter++)
				{
					slice = ChooseSlice(*iter, bpm, timesig, rhythm, keysig);
					if (slice != NULL) // otherwise we just keep it
					{
						cues.push_back(slice->GetCue());
						bpm = slice->GetBPM();
						timesig = slice->GetTimeSig();
						rhythm = slice->GetRhythm();
						keysig = slice->GetKeySig();
					}
				}
				return cues;
				

			}

			AdaptiveSlice* AdaptiveEnvironment::ChooseSlice(String category, float bpm, Vector2 timesig, String rhythm, String keysig)
			{

				DynamicList<AdaptiveSlice*> chosen;
				//Random rand = new Random();

				//srand(); // seed the value with some sort of seed -- system time or something
				float randVal = (float)rand()/(float)RAND_MAX;


				float chance = 0.0f;
				float currentPosition = 0.0f;
				//double randVal = rand.NextDouble();
				float importanceTotal = 0.0f;
				float percentageTotal = 0.0f; // silly sounding!

				// there's got to be a better way to do this, but...
				//foreach (AdaptiveSlice slice in m_slices)
				for (DynamicList<AdaptiveSlice*>::iterator iter = this->m_pSlices.begin(); iter < this->m_pSlices.end(); iter++)
				{
					// we have to get the total importance so we can figure out each chance,
					// and we only want things that have a chance of playing
					if ((*iter)->GetCategory() == category && (*iter)->CalculateProbability() != 0.0f)
					{
						importanceTotal += (*iter)->GetImportance();
					}
				}

				// we'll need to get the total chance to make a 0-1 spread later
				float totalChance = 0.0f;
				//foreach (AdaptiveSlice slice in m_slices)
				for (DynamicList<AdaptiveSlice*>::iterator iter = this->m_pSlices.begin(); iter < this->m_pSlices.end(); iter++)
				{
					// make sure we match all the previous things
					if ((*iter)->GetCategory() == category)
					{
						if (((*iter)->GetBPM() == bpm || bpm == 0.0f) && ((*iter)->GetTimeSig() == timesig || timesig == Vector2(0, 0)))
						{
							if ( ((*iter)->GetRhythm() == rhythm || rhythm == "") && ((*iter)->GetKeySig() == keysig || keysig == ""))
							{
						
								// (percentage * importance) / totalImportance balances our chance of playing with its priority
								chance = (((*iter)->CalculateProbability() * (*iter)->GetImportance()) / (importanceTotal));
			                    
								// on the offchance we have an importance of 0, we don't want to crash
								//if (float.IsNaN(chance))
								//{
									//chance = 0; // this means it either wasn't important or we had no chance of it.
								//}
								(*iter)->SetChance(chance);
								chosen.push_back((*iter));
								totalChance += chance;
							}
						}
					}
				}

				// throw the bones
				if (chosen.size() != 0 && totalChance != 0.0f)
				{
					//foreach (AdaptiveSlice slice in chosen)
					for (DynamicList<AdaptiveSlice*>::iterator iter = chosen.begin(); iter < chosen.end(); iter++)
					{
						if ((*iter)->GetCategory() == category)
						{
							// we go through each and increment how much chance we've gone through
							// we SHOULD never miss, but if we do, we null it out and check for it later
							currentPosition += ((*iter)->GetChance() * (1/totalChance)); // we need to balance it out so we're going 0-1 in the end
							if (currentPosition > randVal)
							{
								//slice.Cue.Play();
								//slice.PlayCue();
								if (*iter != NULL)
									return (*iter);
							}
						}
					}
				}

				


				return NULL; // BAD.
			}

			void AdaptiveEnvironment::LoadEnvironmentFromXml(String path)
			{
				std::ifstream file;
				String line;
				String element;
				String data;
				int substrIndex = 0;
				int substrIndex2 = 0;
				int substrLength = 0;

				AdaptiveSlice* slice;
				AdaptiveParameter* param;
				AdaptiveProperty* prop;
				AdaptivePropertyPoint point;


				file.open(path.c_str());
				if (!file)
					throw SingularityException("Adaptive environment filepath could not be opened.");

				while (file >> line)
				{
					substrIndex = line.find('<') + 1;
					substrIndex2 = line.find('>') - 1;
					//if ((substrIndex = line.find('<')) >= 0)
					if (substrIndex >= 0)
					{
						element = line.substr(substrIndex, substrIndex2); // start after the < and end before the >
						if (element == "environmentname")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							this->m_pName = data;
						}
						if (element == "settingspath")
						{
							// oh no, we have to load in another xact path???
							// or I can just put in slices in triggerhappy?

							// let's work under the assumption that two of them is a BAD
							// thing and that it'll be in TriggerHappy (for now)

							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
						}
						if (element == "wavebankpath")
						{
							// ...which will mean that all of these are wrong. oops.
							// for now, we'll also assume that they'll load slices in ahead of time.
							// that's what you get when you're running low on time!

							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							//AudioManager::Instantiate()->LoadWaveBank(data);
						}
						if (element == "soundbankpath")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							//AudioManager::Instantiate()->LoadSoundBank(data);
						}
						if (element == "categoryname")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							this->m_pCategories.push_back(data);
						}
						if (element == "parameter")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							param = new AdaptiveParameter("", 0, 0);
							this->m_pParameters.push_back(param);
						}
						if (element == "parametername")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							param->SetName(data);
						}
						if (element == "min")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							param->SetMin((float)atof(data.c_str()));
						}
						if (element == "max")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							param->SetMax((float)atof(data.c_str()));
						}
						if (element == "slice")
						{
							slice = new AdaptiveSlice("", "", "", "", Vector2(0,0), 0, "", 0);
							this->m_pSlices.push_back(slice);
						}
						if (element == "slicename")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetName(data);
						}
						if (element == "slicecategory")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetCategory(data);
						}
						if (element == "rhythm")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetRhythm(data);
						}
						if (element == "timesigx")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetTimeSig(Vector2((float)atof(data.c_str()), slice->GetTimeSig().y));
						}
						if (element == "timesigy")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetTimeSig(Vector2(slice->GetTimeSig().x, (float)atof(data.c_str())));
						}
						if (element == "keysig")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetKeySig(data);
						}
						if (element == "bpm")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetBPM((float)atof(data.c_str()));
						}
						if (element == "cuename")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetCue(AudioManager::Instantiate()->CreateCue(data));
						}
						if (element == "sliceimportance")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							slice->SetImportance((float)atof(data.c_str()));
						}
						if (element == "property")
						{
							prop = new AdaptiveProperty("", param, 0);
							slice->AddProperty(prop);
						}
						if (element == "propertyname")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							prop->SetName(data);
						}
						if (element == "propertyparametername")
						{	
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							// find the name in the parameters and attach it
						}
						if (element == "propertyimportance")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							prop->SetImportance((float)atof(data.c_str()));
						}
						if (element == "point")
						{
							
						}
						if (element == "pointx")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							point.position.x = (float)atof(data.c_str());
						}
						if (element == "pointy")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							point.position.y = (float)atof(data.c_str());
						}
						if (element == "curve")
						{
							substrLength = line.find(('<'),substrIndex2+2);
							data = line.substr(substrIndex2 + 2, substrLength - substrIndex2 - 2);
							if (data == "Linear")
							{
								point.curve = LINEAR;
							}
							prop->DefinePoint(point);
						}

					}
					else
					{
						// switch won't work so we'll have it to if it
						
						// element parameters here


					}
				}

			}

			void AdaptiveEnvironment::AddSlice(AdaptiveSlice* slice)
			{
				m_pSlices.push_back(slice);
			}

			void AdaptiveEnvironment::AddParameter(AdaptiveParameter* param)
			{
				m_pParameters.push_back(param);
			}

			void AdaptiveEnvironment::AddCategory(String category)
			{
				m_pCategories.push_back(category);
			}

			String AdaptiveEnvironment::GetName()
			{
				return m_pName;
			}

			void AdaptiveEnvironment::SetVariable(String variable, float value)
			{
				for (DynamicList<AdaptiveParameter*>::iterator iter = m_pParameters.begin(); iter != m_pParameters.end(); iter++)
				{
					if ((*iter)->GetName() == variable)
					{
						(*iter)->SetCurrentValue(value);
					}
				}
			}

		#pragma endregion
	}
}