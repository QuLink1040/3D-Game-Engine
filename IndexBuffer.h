#pragma once
#include <d3d11.h>

class DeviceContext;

class IndexBuffer
{
public:
	IndexBuffer();
	bool load(void* list_indices, UINT size_list);
	UINT getSizeIndexList();
	bool release();
	~IndexBuffer();
private:
	UINT m_size_list;
private:
	ID3D11Buffer * m_buffer;
private:
	friend class DeviceContext;
};