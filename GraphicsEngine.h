#pragma once
#include <d3d11.h>
#include "Prerequisites.h"
#include "RenderSystem.h"

class GraphicsEngine
{
private:
	GraphicsEngine();
	~GraphicsEngine();
	
public:
	RenderSystem* getRenderSystem();
public:
	static GraphicsEngine* get();
	static void create();
	static void release();

private:
	RenderSystem* m_render_system = nullptr;
	static GraphicsEngine* m_engine;
};

