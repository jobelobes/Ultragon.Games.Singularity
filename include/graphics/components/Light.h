#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		enum LightType { Point = 2, Spot = 1, Directional = 0 };

		class Light : public Singularity::Components::Component
		{
			DECLARE_OBJECT_TYPE

			private:
				#pragma region Variables
				LIGHT_DESC	m_kDescription;
				#pragma endregion
		
			protected:
				#pragma region Overriden Methods
				virtual void OnComponentAdded(Singularity::Components::GameObject* gameObject);
				virtual void OnComponentRemoved(Singularity::Components::GameObject* gameObject);
				#pragma endregion

			public:
				#pragma region Properties
				const LightType Get_Type() const;
				void Set_Type(const LightType value);

				const Color Get_Color() const;
				void Set_Color(Color value);

				const float Get_Falloff() const;
				void Set_Falloff(const float value);

				const float Get_Range() const;
				void Set_Range(const float value);

				const float Get_Intensity() const;
				void Set_Intensity(const float value);
				#pragma endregion

				#pragma region Constructors and Finalizers
				Light(LightType type = LightType::Point, Color color = Color(1,1,1,1));
				Light(String name, LightType type = LightType::Point, Color color = Color(1,1,1,1));
				~Light();
				#pragma endregion
				
				friend class Singularity::Graphics::Devices::DrawingContext;
				friend class Singularity::Graphics::Devices::DeferredDrawingContext;
		};

		#include "graphics\components\Light.inc"
	}
}