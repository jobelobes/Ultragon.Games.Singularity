#include "audio\Singularity.Audio.h"

/*
* AdaptiveProperty.h
*
* An adaptive property with points for defining a curve.
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

		enum AdaptivePropertyCurve { LINEAR, COSINE, EXPONENTIAL, LOGARITHMIC };

		struct AdaptivePropertyPoint
		{
			Vector2		position;
			AdaptivePropertyCurve curve;
		};

		class AdaptiveProperty
		{
			private:
			
			#pragma region Variables
				

				float m_fImportance;
				DynamicList<AdaptivePropertyPoint> m_pPoints;
				AdaptiveParameter* m_pParent;
				String m_pName;

				float FindValueOnCurve(float currentPoint, AdaptivePropertyPoint startPoint, AdaptivePropertyPoint endPoint);

			#pragma endregion

			public:

			#pragma region Constructors and Finalizers

				// Constructor.
				AdaptiveProperty(String name, AdaptiveParameter* parent, float importance);

				// Destructor.
				~AdaptiveProperty();

			#pragma endregion

			#pragma region Methods

				AdaptiveParameter* GetParent();
				String GetName();
				float GetImportance();

				void DefinePoint(AdaptivePropertyPoint point);

				void SetName(String name);
				void SetImportance(float importance);

				float GetValueAtPoint(float xval);
				// we don't need to modify values and all that jazz
				

			#pragma endregion
		};
	}
}