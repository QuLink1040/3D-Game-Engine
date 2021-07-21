#pragma once
#include "ResourceManager.h"

class TextureManager : public ResourceManager
{
public:
	TextureManager();
	~TextureManager();

private:
	virtual Resource* createResourceFromFileConcrete(const wchar_t* file_path) = 0;
};

