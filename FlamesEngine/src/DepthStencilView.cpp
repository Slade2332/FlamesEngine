#include "DepthStencilView.h"
#include "Device.h"
#include "DeviceContext.h"

void
DepthStencilView::init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format) {
	if (device.m_device == nullptr) {
		WARNING("ERROR: Device::DepthStencilView::init : Error in data from params [CHECK FOR Device device]\n");
		exit(1);
	}
	else if (depthStencil == nullptr) {
		WARNING("ERROR: Device::DepthStencilView::init : Error in data from params [CHECK FOR ID3D11Resource* depthStencil]\n");
		exit(1);
	}
	else {
		// Configurar la descripción de la vista de profundidad y stencil
		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		memset(&descDSV, 0, sizeof(descDSV));
		descDSV.Format = format; // Establecer el formato
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D; // Establecer la dimensión de la vista
		descDSV.Texture2D.MipSlice = 0; // Establecer el nivel mip
		device.CreateDepthStencilView(depthStencil, &descDSV, &m_depthStencilView); // Crear la vista de profundidad y stencil
	}
}

void
DepthStencilView::update() {
	// Función vacía de actualización
}

void
DepthStencilView::render(DeviceContext& deviceContext) {
	deviceContext.ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0); // Limpiar la vista de profundidad y stencil
}

void
DepthStencilView::destroy() {
	SAFE_RELEASE(m_depthStencilView); // Liberar la vista de profundidad y stencil
}