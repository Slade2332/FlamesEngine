#pragma once
#include "Prerequisites.h"

class Window
{
public:
	Window(); // Constructor predeterminado
	~Window(); // Destructor predeterminado

	/// <summary>
	/// The method is in charge of generating a window
	/// </summary>
	/// <param name="hInstance"> A single ID for the window / Copy of the resource </param>
	/// <param name="nCmdShow"> Command List Window </param>
	/// <param name="wndproc"> Input bridge </param>
	/// <returns></returns>
	HRESULT
		init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc); // Funci�n para inicializar la ventana

	void
		update(); // Funci�n para actualizar la ventana

	void
		render(); // Funci�n para renderizar la ventana

	void
		destroy(); // Funci�n para destruir la ventana

public:
	unsigned int m_width; // Ancho de la ventana
	unsigned int m_height; // Alto de la ventana
	HWND m_hWnd = nullptr; // Identificador de la ventana

private:

	HINSTANCE m_hInst = nullptr; // Identificador de la instancia de la aplicaci�n
	RECT m_rect; // Rect�ngulo para el tama�o de la ventana

	std::string n_windowName = "FlamesEngine"; // Nombre de la ventana
};