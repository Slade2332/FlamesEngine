#include "Device.h"

void Device::init()
{

}

void Device::update()
{

}

void Device::render()
{

}

// Función para destruir el dispositivo
void Device::destroy()
{
	SAFE_RELEASE(m_device); // Liberar el dispositivo de gráficos
}

// Función para crear una vista de destino de renderización
HRESULT Device::CreateRenderTargetView(ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
	ID3D11RenderTargetView** ppRTView) {

	HRESULT hr = S_OK;
	// Verificar si el recurso y la vista de destino de renderización no son nulos
	if (pResource != nullptr || ppRTView != nullptr)
	{
		hr = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView); // Crear la vista de destino de renderización
		WARNING("Device::Device::CreateRenderTargetView : [CREATION OF RESOURCE : OK] \n") // Advertencia de creación exitosa
	}
	else
	{
		WARNING("ERROR::Device::CreateRenderTargetView : Error in data params[CHECK FOR CREATION METHOD : OK] \n"); // Advertencia de error en los parámetros
		exit(1); // Salir con código de error
	}
	return hr; // Devolver el resultado de la operación
}

// Función para crear una textura 2D
HRESULT Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Texture2D** ppTexture2D) {

	HRESULT hr = S_OK;
	if (pDesc != nullptr || ppTexture2D != nullptr) {
		hr = m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D); // Crear la textura 2D
		WARNING("Device::Device::CreateTexture2D : [CREATION OF RESOURCE : OK] \n") // Advertencia de creación exitosa
	}
	else
	{
		WARNING("ERROR::Device::CreateTexture2D : Error in data params[CHECK FOR CREATION METHOD : OK] \n"); // Advertencia de error en los parámetros
		exit(1); // Salir con código de error
	}
	return hr; // Devolver el resultado de la operación
}

// Función para crear una vista de profundidad y stencil
HRESULT Device::CreateDepthStencilView(ID3D11Resource* pResource,
	const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
	ID3D11DepthStencilView** ppDepthStencilView)
{
	HRESULT hr = S_OK;
	// Verificar si el recurso y la vista de profundidad y stencil no son nulos
	if (pResource == nullptr) {
		WARNING("ERROR: Device::Device::CreateDepthStencilView : Error in data from params [Check for ID3D11Resource* pResource] \n") // Advertencia de error en el recurso
	}
	else if (ppDepthStencilView == nullptr) {

		WARNING("ERROR::Device::CreateDepthStencilView : Error in data params[CHECK FOR ID3D11DepthStencilView** ppDepthStencilView] \n"); // Advertencia de error en los parámetros
		exit(1); // Salir con código de error
	}
	else {
		hr = m_device->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView); // Crear la vista de profundidad y stencil
		WARNING("Device::CreateDepthStencilView : [CREATION OF RESOURCE: OK] \n"); // Advertencia de creación exitosa
	}

	return hr; // Devolver el resultado de la operación
}