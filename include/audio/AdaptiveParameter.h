#include "audio\Singularity.Audio.h"

/*
* AdaptiveParameter.h
*
* An adaptive parameter that we can get the current setting from.
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

		class AdaptiveParameter
		{
			private:
			
			#pragma region Variables
				
				String m_pName;
				float m_fMin;
				float m_fMax;
				float m_fCurrent;

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveParameter(String name, float min, float max);

				// Destructor.
				~AdaptiveParameter();

			#pragma endregion

			#pragma region Methods

				String GetName();
				float GetMin();
				float GetMax();
				float GetCurrentValue();

				void SetCurrentValue(float value);

				void SetName(String name);
				void SetMin(float min);
				void SetMax(float max);

			#pragma endregion
		};
	}
}