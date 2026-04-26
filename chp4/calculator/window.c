// #include:
#include <windows.h>

// #pragma:
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

// Global callback function prototype/s:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry-point function:
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Variable declarations:
	WNDCLASSEX wndclass;
	TCHAR szClassName[] = TEXT("window");
	HWND hwnd;
	MSG msg;

	// Code:
	wndclass.cbSize = (sizeof(WNDCLASSEX));
	wndclass.style = (CS_HREDRAW | CS_VREDRAW);
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = ((HBRUSH)(GetStockObject(BLACK_BRUSH)));
	wndclass.hIcon = (LoadIcon(NULL, IDI_APPLICATION));
	wndclass.hIconSm = (LoadIcon(NULL, IDI_APPLICATION));
	wndclass.hCursor = (LoadCursor(NULL, IDC_ARROW));
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;

	// Registering window class:
	RegisterClassEx(&wndclass);

	// Creating the window:
	hwnd = CreateWindow(szClassName,
						(TEXT("window")),
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						NULL,
						NULL,
						hInstance,
						NULL
	);

	// Showing the window :
	ShowWindow(hwnd, iCmdShow);
	
	// Updating the window:
	UpdateWindow(hwnd); // Sends 'WM_PAINT' to the process of this program. 'WM_PAINT' is the heart of event-driven architecture!

	// Message loop:
	while ((GetMessage(&msg, NULL, 0, 0)))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return(((int)(msg.wParam)));

}

// CallBack Window Procedure:
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static INT_PTR openCalC(HINSTANCE*, HWND, UINT, WPARAM, LPARAM);
	/* ... */
	HINSTANCE hLib = 0;

	// Handling messages:
	switch (iMsg)
	{
	case WM_CREATE:
		openCalC(&hLib, hwnd, iMsg, wParam, lParam);
		break;

	case WM_DESTROY:
		if(hLib) FreeLibrary(hLib);
		PostQuitMessage(0);
		break;

	default:
		break;
	}

	return((DefWindowProc(hwnd, iMsg, wParam, lParam))); // 'DefWindowProc' is a window procedure of the OS.

}

static INT_PTR openCalC(HINSTANCE* empHInst, HWND hParent, UINT msg, WPARAM wParam, LPARAM lParam)
{
	typedef INT_PTR(*dlgproc)(HINSTANCE, HWND, UINT, WPARAM, LPARAM);
	dlgproc calc;

	*empHInst = LoadLibrary("dlgbox.dll");
	calc = (dlgproc)GetProcAddress(*empHInst, "createDlgBox");

	return(calc(NULL, hParent, msg, wParam, lParam));
}
