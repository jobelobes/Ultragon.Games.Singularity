#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		namespace Devices
		{
			class DeferredDrawingContext : public DrawingContext
			{
				private:
					#pragma region Static Variables
					//Materials for the system
					static Singularity::Graphics::Material*	g_pGBufferMaterial;
					static Singularity::Graphics::Material*	g_pLightingMaterial;
					static Singularity::Graphics::Material*	g_pCombineMaterial;
					#pragma endregion

					#pragma region Variables
					Singularity::Graphics::RenderTexture*				m_pRenderTargets[5];		//0 = diffuse, 1 = normal map, 2 = depth buffer, 3 = light, 4 = combine
					/*Singularity::Graphics::RenderTexture*				m_pLightRenderTarget;
					Singularity::Graphics::RenderTexture*				m_pCombineRenderTarget;*/

					//Pass 1 Descriptions
					//ID3D10Texture2D*			m_pGBufferTextures[3];
					//ID3D10RenderTargetView*	m_pGBufferRenderTargetView[3];
					//ID3D10ShaderResourceView*	m_pGBufferShaderResourceView[3];

					////Pass 2 Descriptions
					//ID3D10Texture2D*			m_pLightTexture;
					//ID3D10RenderTargetView*	m_pLightRenderTargetView;
					//ID3D10ShaderResourceView*	m_pLightShaderResourceView;
					//

					////Pass 3 Descriptions
					//ID3D10Texture2D*			m_pCombineTexture;
					//ID3D10RenderTargetView*	m_pCombineRenderTargetView;
					//ID3D10ShaderResourceView*	m_pCombineShaderResourceView;

					//Used in some of the light calculations
					Vector2						m_pHalfPixel;

					//Vertex and Indice Buffers for rendering quads to the screen
					VertexBuffer*				m_pVertexBuffer;
					VertexPositionTexture*		m_pVertices;
					IndexBuffer*				m_pIndexBuffer;
					RenderState					m_pLightRenderState;
					RenderState					m_pRenderState;

					unsigned					m_pLayer;
					#pragma endregion

					#pragma region Methods
					//Method to build the resources for the render targets
					//void _BuildResources(unsigned width, unsigned height);

					
					void _ResolveBuffer();

					void _ClearGBufferTargets();

					void _RenderLightMap();

					void _RenderFinalScene();

					void _RenderQuad();
					#pragma endregion

				protected:
					#pragma region Overriden Methods
					void Draw(unsigned length, unsigned start);

					void DrawIndexed(unsigned length, unsigned start, unsigned vertexOffset);
					#pragma endregion

				public:
					#pragma region Constructors and Finalizers
					DeferredDrawingContext();
					~DeferredDrawingContext();
					#pragma endregion

					#pragma region Overriden Methods
					DeferredDrawingContext* Clone() { return new DeferredDrawingContext(); };

					void SetLayer(unsigned layer);

					void Flush();

					void Draw(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, int start = -1, int length = -1);

					void DrawIndexed(Camera* camera, Material* material, Matrix& world, VertexBuffer* vertices, IndexBuffer* indices, int start = -1, int length = -1, int vertexOffset = -1);
					#pragma endregion

					#pragma region Methods
					//Methods to handle the deferred rendering process
					void SetGBuffer();
					#pragma endregion

					#pragma region Static Methods
					static Material* CreateDeferredGBufferMaterial();
					static Material* CreateDeferredLightingMaterial();
					static Material* CreateDeferredCombineMaterial();
					#pragma endregion
			};
		}
	}
}