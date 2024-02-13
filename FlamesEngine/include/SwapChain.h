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
			Window window); // Función para inicializar el intercambiador de imágenes

	void
		update(); // Función para actualizar el intercambiador de imágenes

	void
		render(); // Función para renderizar el intercambiador de imágenes

	void
		destroy(); // Función para destruir el intercambiador de imágenes

public:
	IDXGISwapChain* m_swapChain = nullptr; // Intercambiador de imágenes

private:
	D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL; // Tipo de controlador de DirectX
	D3D_FEATURE_LEVEL m_feature_level = D3D_FEATURE_LEVEL_11_0; // Nivel de características de DirectX
};