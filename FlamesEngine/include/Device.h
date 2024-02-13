#pragma once
#include "Prerequisites.h"

class Device 
{
public:
	Device() = default;
	~Device() = default;

	void
		init();

	void
		update();

	void
		render();

	void
		destroy();

	HRESULT
		CreateRenderTargetView(ID3D11Resource* pResource,
			const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
			ID3D11RenderTargetView** ppRTView); // Funci�n para crear una vista de destino de renderizaci�n

	HRESULT
		CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Texture2D** ppTexture2D); // Funci�n para crear una textura 2D

	HRESULT
		CreateDepthStencilView(ID3D11Resource* pResource,
			const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
			ID3D11DepthStencilView** ppDepthStencilView); // Funci�n para crear una vista de profundidad y stencil

	HRESULT
		CreateVertexShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11VertexShader** ppVertexShader); // Funci�n para crear un shader de v�rtices

	HRESULT
		CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
			unsigned int NumElements,
			const void* pShaderBytecodeWithInputSignature,
			unsigned int BytecodeLength,
			ID3D11InputLayout** ppInputLayout); // Funci�n para crear un dise�o de entrada

	HRESULT
		CreatePixelShader(const void* pShaderBytecode,
			unsigned int BytecodeLength,
			ID3D11ClassLinkage* pClassLinkage,
			ID3D11PixelShader** ppPixelShader); // Funci�n para crear un shader de p�xeles

	HRESULT
		CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
			const D3D11_SUBRESOURCE_DATA* pInitialData,
			ID3D11Buffer** ppBuffer); // Funci�n para crear un b�fer

	HRESULT CreateSamplerState(
		const D3D11_SAMPLER_DESC* pSamplerDesc,
		ID3D11SamplerState** ppSamplerState); // Funci�n para crear un estado de muestreo

public:
	ID3D11Device* m_device = nullptr; // Dispositivo de gr�ficos
};
