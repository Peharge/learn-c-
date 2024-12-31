#include <windows.h>

// Globale Variablen:
HINSTANCE hInst;  // Instanz des Programms
LPCWSTR szWindowClass = L"MeinFenster";  // Fensterklassename
LPCWSTR szTitle = L"Meine Visual C++ GUI"; // Fenstertitel

// Funktionsprototypen:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Die Hauptfunktion für die Anwendung
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wcex;
    ZeroMemory(&wcex, sizeof(WNDCLASSEX));

    // Fensterklasse definieren
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc; // Fensterprozedur
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.lpszClassName = szWindowClass;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL, L"Fensterklasse konnte nicht registriert werden", L"Fehler", MB_ICONERROR);
        return 1;
    }

    // Fenster erstellen
    HWND hWnd = CreateWindowEx(0, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, NULL, NULL, hInstance, NULL);

    if (!hWnd)
    {
        MessageBox(NULL, L"Fenster konnte nicht erstellt werden", L"Fehler", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Nachrichten-Schleife
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

// Fensterprozedur
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == 1) // Wenn der Button geklickt wird
        {
            MessageBox(hWnd, L"Button wurde geklickt!", L"Info", MB_OK);
        }
        break;

    case WM_CREATE:
        // Button erstellen
        CreateWindow(L"BUTTON", L"Click Me", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            150, 100, 200, 50, hWnd, (HMENU)1, hInst, NULL);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
