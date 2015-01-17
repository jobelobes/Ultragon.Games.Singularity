#include "graphics\Singularity.Graphics.h"

namespace Singularity
{
	namespace Graphics
	{
		#pragma region Constructors and Finalizers
		Texture2D::Texture2D(ID3D10Device* device, ID3D10Texture2D* texture)
			: m_pDevice(device), m_pTexture(texture), m_pShaderResView(NULL), m_pTextureBuffer(NULL), m_iRowSpan(0), m_bDirty(false)
		{
			D3D10_SHADER_RESOURCE_VIEW_DESC srvDesc;
			ID3D10Blob* buffer;
			HRESULT hr;

			this->m_pTexture->GetDesc(&this->m_kDescription);

			srvDesc.Format = this->m_kDescription.Format;
			srvDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURE2D;

			// These didn't work, so they're now temporarily hardcoded

			//srvDesc.Texture2D.MipLevels = this->m_kDescription.MipLevels;
			srvDesc.Texture2D.MipLevels = 1;
			//srvDesc.Texture2D.MostDetailedMip = this->m_kDescription.MipLevels - 1;
			srvDesc.Texture2D.MostDetailedMip = 0; // this must be between 0 and MipLevels - 1

			hr = this->m_pDevice->CreateShaderResourceView(this->m_pTexture, &srvDesc, &this->m_pShaderResView);
			if(FAILED(hr))
				throw SingularityException("Unable to create texture object.", hr);

			D3DX10SaveTextureToMemory(this->m_pTexture, D3DX10_IFF_BMP, &buffer, 0);
			this->m_pTextureBuffer = (unsigned char*)malloc(buffer->GetBufferSize());
			memcpy(this->m_pTextureBuffer, buffer->GetBufferPointer(), buffer->GetBufferSize());
			buffer->Release();
		}

		Texture2D::Texture2D(unsigned width, unsigned height, bool mipmap)
			: m_pDevice(NULL), m_pTexture(NULL), m_pShaderResView(NULL), m_pTextureBuffer(NULL), m_iRowSpan(0), m_bDirty(false)
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
			this->m_kDescription.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			this->m_kDescription.SampleDesc.Count = 1;
			this->m_kDescription.Usage = D3D10_USAGE_DEFAULT;
			this->m_kDescription.BindFlags = D3D10_BIND_RENDER_TARGET | D3D10_BIND_SHADER_RESOURCE;

			srvDesc.Format = this->m_kDescription.Format;
			srvDesc.ViewDimension = D3D10_SRV_DIMENSION_TEXTURE2D;
			srvDesc.Texture2D.MipLevels = this->m_kDescription.MipLevels;
			srvDesc.Texture2D.MostDetailedMip = this->m_kDescription.MipLevels - 1;
			
			hr = this->m_pDevice->CreateTexture2D(&this->m_kDescription, NULL, &this->m_pTexture);
			if(FAILED(hr))
				throw SingularityException("Unable to create texture object.", hr);

			hr = this->m_pDevice->CreateShaderResourceView(this->m_pTexture, &srvDesc, &this->m_pShaderResView);
			if(FAILED(hr))
				throw SingularityException("Unable to create shader resource view object.", hr);

			hr = D3DX10SaveTextureToMemory(this->m_pTexture, D3DX10_IFF_BMP, &buffer, 0);
			if(FAILED(hr))
				throw SingularityException("Unable to save texture to memory. ", hr);

			this->m_pTextureBuffer = (unsigned char*)malloc(buffer->GetBufferSize());
			memcpy(this->m_pTextureBuffer, buffer->GetBufferPointer(), buffer->GetBufferSize());
			buffer->Release();
		}

		Texture2D::~Texture2D()
		{
			if(this->m_pTexture != NULL)
				this->m_pTexture->Release();

			if(this->m_pShaderResView != NULL)
				this->m_pShaderResView->Release();
		}
		#pragma endregion
		
		#pragma region Methods
		void Texture2D::SetPixel(unsigned x, unsigned y, Color color)
		{
			unsigned index = x + y * this->m_iRowSpan;
			this->m_pTextureBuffer[index] = color;

			this->m_bDirty = true;
		}

		void Texture2D::SetPixels(void* buffer, int size, int level)
		{
			memcpy(&this->m_pTextureBuffer, buffer, size);

			this->m_bDirty = true;
		}

		Color Texture2D::GetPixel(unsigned x, unsigned y, bool force)
		{
			ID3D10Blob* buffer;
			unsigned index = ((BITMAPFILEHEADER*)this->m_pTextureBuffer)->bfOffBits + x * 4 + (this->m_kDescription.Height - y - 1) * this->m_kDescription.Width * 4;
			if(force)
			{
				D3DX10SaveTextureToMemory(this->m_pTexture, D3DX10_IFF_BMP, &buffer, 0);
				memcpy(this->m_pTextureBuffer, buffer->GetBufferPointer(), buffer->GetBufferSize());
				buffer->Release();
			}

			return Color(this->m_pTextureBuffer[index+2] / 255.0f, this->m_pTextureBuffer[index+1] / 255.0f, this->m_pTextureBuffer[index] / 255.0f, this->m_pTextureBuffer[index+3] / 255.0f);
		}

		void Texture2D::Apply()
		{
			if(this->m_bDirty)
			{
				D3D10_MAPPED_TEXTURE2D mappedTex;
				this->m_pTexture->Map(D3D10CalcSubresource(0, 0, 1), D3D10_MAP_WRITE_DISCARD, 0, &mappedTex);
				memcpy(&mappedTex.pData, this->m_pTextureBuffer, this->m_kDescription.ArraySize);
				this->m_pTexture->Unmap(D3D10CalcSubresource(0, 0, 1));

				this->m_bDirty = false;
			}
		}
		#pragma endregion
 
		#pragma region Static Methods
		Texture2D* Texture2D::LoadTextureFromFile(String path)
		{
			ID3D10Resource* texture;
			ID3D10Device* device;
			D3D10_RESOURCE_DIMENSION type;
			HRESULT hr; 

			device = Singularity::Graphics::Devices::HardwareDevice::Instance->m_pDevice;
			hr = D3DX10CreateTextureFromFile(device, path.c_str(), NULL, NULL, &texture, NULL);
			if(FAILED(hr))
				throw SingularityException(String("Unable to load texture file \"").append(path).append("\":").c_str(), hr);

			texture->GetType(&type);
			if(type != D3D10_RESOURCE_DIMENSION_TEXTURE2D)
				throw SingularityException("Texture loaded was not a valid texture type."); 
 
			return new Texture2D(device, (ID3D10Texture2D*)texture);
		}
		#pragma endregion
	}
}