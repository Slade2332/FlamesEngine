#pragma once
#include "Prerequisites.h"

class DeviceContext
{
public:
	DeviceContext() = default; // Constructor predeterminado
	~DeviceContext() { SAFE_RELEASE(m_deviceContext); }; // Destructor

	void
		init(); // Función para inicializar el contexto de dispositivo

	void
		update(); // Función para actualizar el contexto de dispositivo

	void
		render(); // Función para renderizar el contexto de dispositivo

	void
		destroy(); // Función para destruir el contexto de dispositivo

	// Función para limpiar la vista de profundidad y stencil
	void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		unsigned int Stencil);

	// Función para establecer recursos de shader de píxeles
	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

public:
	ID3D11DeviceContext* m_deviceContext = nullptr; // Contexto de dispositivo
};