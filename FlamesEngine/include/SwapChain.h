#pragma once
#include "Prerequisites.h"
class Device;
class DeviceContext;
class Window;
class Texture;

class SwapChain {
public:
	SwapChain() = default; // Constructor predeterminado
	~SwapChain() { SAFE_RELEASE(m_swapChain); }; // Destructor

	void
		init(Device& device,
			DeviceContext& deviceContext,
			Texture& backBuffer,
			Window window); // Funci�n para inicializar el intercambiador de im�genes

	void
		update(); // Funci�n para actualizar el intercambiador de im�genes

	void
		render(); // Funci�n para renderizar el intercambiador de im�genes

	void
		destroy(); // Funci�n para destruir el intercambiador de im�genes

public:
	IDXGISwapChain* m_swapChain = nullptr; // Intercambiador de im�genes

private:
	D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL; // Tipo de controlador de DirectX
	D3D_FEATURE_LEVEL m_feature_level = D3D_FEATURE_LEVEL_11_0; // Nivel de caracter�sticas de DirectX
};