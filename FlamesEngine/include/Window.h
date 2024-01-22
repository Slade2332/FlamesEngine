#pragma once
#include "Prerequisites.h"
class Window
{
public:
	Window();
	~Window();

	/// <summary>
	/// The methos is in charge of generate a window
	/// </summary>
	/// <param name="hInstance"> A single ID for the window / Copy of the resource </param>
	/// <param name="nCmdShow"> Command List Window </param>
	/// <param name="wndproc"> Input bridge </param>
	/// <returns></returns>

	HRESULT
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	void
		update();

	void
		render();

	void
		destroy();

public:
	unsigned int m_width;
	unsigned int m_height;
	HWND m_hWnd = nullptr;
private:
	
	HINSTANCE m_hInst = nullptr;
	RECT m_rect;
	
	std::string n_windowName = "FlamesEngine";

}; 
