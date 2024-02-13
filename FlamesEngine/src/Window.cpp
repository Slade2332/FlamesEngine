#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

HRESULT Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc)
{
    m_hInst = hInstance; // Establecer el identificador de instancia

    // Registrar clase de ventana
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndproc; // Establecer el procedimiento de ventana
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "TutorialWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1);
    if (!RegisterClassEx(&wcex))
        return E_FAIL;

    // Crear ventana
    RECT rc = { 0, 0, 640, 480 };
    m_rect = rc;
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    m_hWnd = CreateWindow("TutorialWindowClass",
        "Direct3D 11 Tutorial 7",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        m_rect.right - m_rect.left,
        m_rect.bottom - m_rect.top,
        nullptr,
        nullptr,
        m_hInst,
        nullptr);
    if (!m_hWnd)
        return E_FAIL;

    ShowWindow(m_hWnd, nCmdShow); // Mostrar la ventana

    GetClientRect(m_hWnd, &m_rect); // Obtener el tamaño de la ventana
    m_width = m_rect.right - m_rect.left; // Calcular el ancho de la ventana
    m_height = m_rect.bottom - m_rect.top; // Calcular la altura de la ventana

    return S_OK;
}

void
Window::update()
{
    // Función vacía de actualización
}

void
Window::render()
{
    // Función vacía de renderizado
}

void
Window::destroy()
{
    // Función vacía de destrucción
}