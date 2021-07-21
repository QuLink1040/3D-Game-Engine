#include "Texture.h"
#include <DirectXTex.h>

Texture::Texture(const wchar_t* full_path) : Resource(full_path)
{
	DirectX::ScratchImage image_date;
	HRESULT res = DirectX::LoadFromWICFile(full_path, DirectX::WIC_FLAGS_NONE, nullptr, image_data);

	if (SUCCEEDED(res))
	{
		res = DirectX::CreateTexture();
	}
	else
	{
		throw std::exception("Texture not created successfully");
	}
}

Texture::~Texture()
{
}
