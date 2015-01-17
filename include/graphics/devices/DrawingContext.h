#include "graphics\Singularity.Graphics.h"

using namespace Singularity::Graphics;

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			class DrawingContext
			{
				private:
					#pragma region Variables
					HardwareDevice*				m_pHardwareDevice;
					ID3D10Device*				m_pDevice;

					unsigned					m_iLightingCapacity;
					unsigned					m_iLightingCount;
					LIGHT_DESC*					m_pLighting;
					#pragma endregion

				protected:
					#pragma region Properties
					inline HardwareDevice* Get_HardwareDevice() const { return this->m_pHardwareDevice; };

					inline ID3D10Device* Get_InternalDevice() const { return this->m_pDevice; };

					inline LIGHT_DESC* Get_Lights() { return this->m_pLighting; }

					inline unsigned Get_LightCount() { return this->m_iLightingCount; }

					inline unsigned Get_LightCapacity() { return this->m_iLightingCapacity; }
					#pragma endregion

					#pragma region Methods
					virtual void SetLighting(LIGHT_DESC* light, unsigned count) { };

					virtual void SetInputLayout(ID3D10InputLayout* inputlayout);

					virtual void SetVertexBuffer(ID3D10Buffer* buffer, unsigned stride, unsigned start, unsigned length);

					virtual void SetIndexBuffer(ID3D10Buffer* buffer, DXGI_FORMAT format, unsigned start, unsigned length);
					
					virtual void SetMaterial(Material* material);

					virtual void SetPass(ID3D10EffectPass* pass);

					virtual void Draw(unsigned length, unsigned start);

					virtual void DrawIndexed(unsigned length, unsigned start, unsigned vertexOffset);
					#pragma endregion

				public:
					#pragma region Constructors and Finalizers
					DrawingContext();
					~DrawingContext();
					#pragma endregion

					#pragma region Methods
					virtual DrawingContext* Clone() { return new DrawingContext(); };

					virtual void Clear(const Color color);

					virtual void Flush();

					virtual void AddLight(Light* light);

					virtual void SetLayer(unsigned layer) { };

					virtual void SetRenderState(RenderState& renderstate);

					virtual void Draw(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, int start = -1, int length = -1);

					virtual void DrawIndexed(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start = -1, int length = -1, int vertexOffset = -1);
					#pragma endregion
			};
		}
	}
}