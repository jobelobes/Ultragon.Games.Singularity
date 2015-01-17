#include "graphics.shapes\Singularity.Graphics.Shapes.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Shapes
		{
			class Grid : public Singularity::Components::GameObject
			{
				private:
					#pragma region Variables
					unsigned		m_iGridSize;
					float			m_fGridScale;
					Color			m_kColor;
					bool			m_bDirty;

					Material*		m_pMaterial;
					MeshRenderer*	m_pRenderer;
					#pragma endregion

					#pragma region Methods
					Mesh* _BuildMesh(unsigned gridSize, float gridScale);
					#pragma endregion

				protected:
					#pragma region Overriden Methods
					void OnGameObjectAdded(GameObject* parent);
					#pragma endregion

				public:
					#pragma region Properties
					inline const Color Get_Color() const{ return this->m_kColor; };
					inline void Set_Color(const Color value) { this->m_kColor = value;};

					inline const unsigned Get_GridSize() const{ return this->m_iGridSize; };
					inline void Set_GridSize(const unsigned value){ this->m_iGridSize = value; this->m_bDirty = true; };

					inline const float Get_GridScale() const{ return this->m_fGridScale; };
					inline void Set_GridScale(const float value){ this->m_fGridScale = value; };
					#pragma endregion

					#pragma region Constructors and Finalizers
					Grid(String name = "", const unsigned gridSize = 16, const float gridScale = 32.0f, const Color color = Color(0xFF,0xFF,0xFF,0xFF));
					~Grid();
					#pragma endregion
			};
		}
	}
}