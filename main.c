#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            if ((HWND)lParam && LOWORD(wParam) == 1)
                MessageBox(hwnd, "Te lo dije, no hace nada. XD", "Error xD", MB_ICONERROR | MB_OK);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "VentanaInutil";

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, "VentanaInutil", "Programa Inutil", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, hInstance, NULL);

    if (!hwnd) return 0;
    
    /* Los botones y lo demás xd */

    CreateWindow("STATIC", "Este programa no hace nada", WS_VISIBLE | WS_CHILD,
                 50, 20, 200, 20, hwnd, NULL, hInstance, NULL);

    CreateWindow("BUTTON", "No Hacer Nada", WS_VISIBLE | WS_CHILD,
                 50, 50, 120, 30, hwnd, (HMENU)1, hInstance, NULL);

    CreateWindow("BUTTON", "Cerrar Manualmente", WS_VISIBLE | WS_CHILD,
                 50, 100, 150, 30, hwnd, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
