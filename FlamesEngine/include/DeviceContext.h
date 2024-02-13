#pragma once
#include "Prerequisites.h"

class DeviceContext
{
public:
	DeviceContext() = default; // Constructor predeterminado
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); }; // Destructor

	void
		init(); // Funci�n para inicializar el contexto de dispositivo

	void
		update(); // Funci�n para actualizar el contexto de dispositivo

	void
		render(); // Funci�n para renderizar el contexto de dispositivo

	void
		destroy(); // Funci�n para destruir el contexto de dispositivo

	// Funci�n para limpiar la vista de profundidad y stencil
	void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		unsigned int Stencil);

	// Funci�n para establecer recursos de shader de p�xeles
	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:
	ID3D11DeviceContext* m_deviceContext = nullptr; // Contexto de dispositivo
};