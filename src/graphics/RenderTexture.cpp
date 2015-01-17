#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Deconstructors
		RenderTexture::RenderTexture(unsigned width, unsigned height, DXGI_FORMAT format)
			: Texture2D(width, height, true)
		{
			this->CreateResource(width, height, format);
		}
		#pragma endregion

		#pragma region Private Methods
		void RenderTexture::CreateResource(unsigned width, unsigned height, DXGI_FORMAT format)
		{
			D3D10_SHADER_RESOURCE_VIEW_DESC srvDesc;
			ID3D10Blob* buffer;
			HRESULT hr;

			this->m_pDevice = Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice;

			memset(&this->m_kDescription, 0, sizeof(D3D10_TEXTURE2D_DESC));
			this->m_kDescription.Width = width;
			this->m_kDescription.Height = height;
			this->m_kDescription.MipLevels = 1;
			this->m_kDescription.ArraySize = 1;
			this->m_kDescription.Format = format;
			this->m_kDescription.SampleDesc.Count = 1;
			this->m_kDescription.Usage = D3D10_USAGE_DEFAULT;
			this->m_kDescription.BindFlags = D3D10_BIND_RENDER_TARGET | D3D10_BIND_SHADER_RESOURCE;

			srvDesc.Format = this->m_kDescription.Format;
			srvDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURE2D;
			srvDesc.Texture2D.MipLevels = this->m_kDescription.MipLevels;
			srvDesc.Texture2D.MostDetailedMip = 0;
			
			hr = this->m_pDevice->CreateTexture2D(&this->m_kDescription, NULL, &this->m_pTexture);
			if(FAILED(hr))
				throw SingularityException("Unable to create texture object.", hr);

			hr = this->m_pDevice->CreateShaderResourceView(this->m_pTexture, &srvDesc, &this->m_pShaderResView);
			if(FAILED(hr))
				throw SingularityException("Unable to shader resource view object.", hr);


			D3D10_RENDER_TARGET_VIEW_DESC rtView;
			rtView.Format = this->m_kDescription.Format;
			rtView.ViewDimension = D3D10_RTV_DIMENSION_TEXTURE2D;
			rtView.Texture2D.MipSlice = 0;

			hr = this->m_pDevice->CreateRenderTargetView(this->m_pTexture, &rtView, &this->m_pRenderTarget);
			if(FAILED(hr))
				throw SingularityException("Unable to create render target view object", hr);

			hr = D3DX10SaveTextureToMemory(this->m_pTexture, D3DX10_IFF_PNG, &buffer, 0);
			if(FAILED(hr))
				throw SingularityException("Unable to save texture to memory. ", hr);

			this->m_pTextureBuffer = (unsigned char*)malloc(buffer->GetBufferSize());
			memcpy(this->m_pTextureBuffer, buffer->GetBufferPointer(), buffer->GetBufferSize());
			buffer->Release();
		}
		#pragma endregion
	}
}