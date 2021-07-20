#pragma once
#include <d3d11.h>
#include "Prerequisites.h"

class SwapChain
{
public:
	SwapChain(HWND hwnd, UINT width, UINT height, RenderSystem* system);

	bool present(bool vsync);

	~SwapChain();
private:
	IDXGISwapChain * m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
	ID3D11DepthStencilView* m_dsv;

	RenderSystem* m_system = nullptr;
private:
	friend class DeviceContext;
};

