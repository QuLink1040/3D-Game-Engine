#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include "RenderSystem.h"
#include "TextureManager.h"	

class GraphicsEngine
{
private:
	GraphicsEngine();
	~GraphicsEngine();
	
public:
	RenderSystem* getRenderSystem();
	TextureManager* getTextureManager();

public:
	static GraphicsEngine* get();
	static void create();
	static void release();

private:
	RenderSystem* m_render_system = nullptr;
	TextureManager* m_tex_manager = nullptr;
	static GraphicsEngine* m_engine;
};

