#include "DeviceContext.h"

void DeviceContext::destroy()
{
    m_deviceContext->ClearState();
}

/// <summary>
/// This class clears the depth-stencil view
/// </summary>
/// <param name="pDepthStencilView"> A pointer to the depth stencil </param>
/// <param name="ClearFlags"> Clear blind flags? </param>
/// <param name="Depth"> Clear depth? </param>
/// <param name="Stencil"> Clear stencil? </param>
void DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
    unsigned int ClearFlags,
    float Depth,
    unsigned int Stencil) {
    if (pDepthStencilView == nullptr) {
        WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11DepthStencilView* pDepthStencilView]\n");
        exit(1);
    }
    else {
        m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
    }
}

/// <summary>
/// Set shader resources to device context
/// </summary>
/// <param name="StartSlot"> First slot to shader resources </param>
/// <param name="NumViews"> ??? </param>
/// <param name="ppShaderResourceViews"> A pointer to shader resource views </param>
void
DeviceContext::PSSetShaderResources(unsigned int StartSlot,
    unsigned int NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews) {
    if (ppShaderResourceViews == nullptr) {
        WARNING("ERROR: DeviceContext::ClearDepthStencilView : Error in data from params [CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews]\n");
        exit(1);
    }
    else {
        m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
    }
}

void DeviceContext::OMSetRenderTargets(unsigned int NumViews,
    ID3D11RenderTargetView* const* ppRenderTargetViews,
    ID3D11DepthStencilView* pDepthStencilView)
{
    if (ppRenderTargetViews == nullptr)
    {
        WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los parámetros [VERIFICAR ID3D11RenderTargetView* const* ppRenderTargetViews]\n")
            exit(1); // Salir del programa si hay un error
    }
    else if (pDepthStencilView == nullptr)
    {
        WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los parámetros [VERIFICAR ID3D11DepthStencilView* pDepthStencilView]\n")
            exit(1); // Salir del programa si hay un error
    }
    else
    {
        m_deviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
    }

}

void
DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
    const float ColorRGBA[4])
{
    if (pRenderTargetView == nullptr)
    {
        WARNING("ERROR: DeviceContext::OMSetRenderTargets : Error en los parámetros [VERIFICAR ID3D11RenderTargetView* pRenderTargetView]\n")
            exit(1); // Salir del programa si hay un error
    }
    else
    {
        m_deviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
    }
}

void DeviceContext::RSSetViewports(unsigned int NumViewports,
    const D3D11_VIEWPORT* pViewports)
{
    m_deviceContext->RSSetViewports(NumViewports, pViewports);
}

void
DeviceContext::IASetInputLayout(ID3D11InputLayout* pInputLayout) {
    m_deviceContext->IASetInputLayout(pInputLayout);
}

void DeviceContext::VSSetShader(ID3D11VertexShader* pVertexShader,
    ID3D11ClassInstance* const* ppClassInstances,
    unsigned int NumClassInstances) {
    m_deviceContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void DeviceContext::PSSetShader(ID3D11PixelShader* pPixelShader,
    ID3D11ClassInstance* const* ppClassInstances,
    unsigned int NumClassInstances) {
    m_deviceContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void DeviceContext::UpdateSubresource(ID3D11Resource* pDstResource,
    unsigned int DstSubresource,
    const D3D11_BOX* pDstBox,
    const void* pSrcData,
    unsigned int SrcRowPitch,
    unsigned int SrcDepthPitch) {
    m_deviceContext->UpdateSubresource(pDstResource,
        DstSubresource,
        pDstBox,
        pSrcData,
        SrcRowPitch,
        SrcDepthPitch);
}

void DeviceContext::IASetVertexBuffer(unsigned int Starlot,
    unsigned int NumBuffers,
    ID3D11Buffer* const* ppVertexBuffers,
    const unsigned int* pStrides,
    const unsigned int* pOffsets)
{
    m_deviceContext->IASetVertexBuffers(Starlot,
        NumBuffers,
        ppVertexBuffers,
        pStrides,
        pOffsets);
}

void DeviceContext::IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
    DXGI_FORMAT format,
    unsigned int Offset)
{
    m_deviceContext->IASetIndexBuffer(pIndexBuffer, format, Offset);
}

void DeviceContext::PSSetSamplers(unsigned int StartSlot,
    unsigned int NumSamplers,
    ID3D11SamplerState* const* ppSamplers)
{
    m_deviceContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}
