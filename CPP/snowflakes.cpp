#include <windows.h>
#include <math.h>

const double PI = 3.14159265358979323846;

void DrawKochLine(HDC hdc, double x1, double y1, double x2, double y2, int depth) {
    if (depth == 0) {
        // Draw a simple line at the lowest recursion depth
        MoveToEx(hdc, (int)x1, (int)y1, NULL);
        LineTo(hdc, (int)x2, (int)y2);
    } else {
        // Recursively divide the line into three parts and create the Koch snowflake shape
        double deltaX = (x2 - x1) / 3;
        double deltaY = (y2 - y1) / 3;

        // Points dividing the line into thirds
        double x3 = x1 + deltaX;
        double y3 = y1 + deltaY;

        double x5 = x2 - deltaX;
        double y5 = y2 - deltaY;

        // Middle point of the triangle created by dividing the line
        double angle = PI / 3; // 60 degrees in radians
        double x4 = (x3 + x5) / 2 - (y5 - y3) * tan(angle);
        double y4 = (y3 + y5) / 2 + (x5 - x3) * tan(angle);

        // Recursively draw the four line segments
        DrawKochLine(hdc, x1, y1, x3, y3, depth - 1);
        DrawKochLine(hdc, x3, y3, x4, y4, depth - 1);
        DrawKochLine(hdc, x4, y4, x5, y5, depth - 1);
        DrawKochLine(hdc, x5, y5, x2, y2, depth - 1);
    }
}

void DrawKochSnowflake(HDC hdc, double x1, double y1, double x2, double y2, int depth) {
    // Calculate the third point of the equilateral triangle
    double x3 = (x1 + x2) / 2 - (y2 - y1) * sqrt(3) / 2;
    double y3 = (y1 + y2) / 2 + (x2 - x1) * sqrt(3) / 2;

    // Draw the three sides of the triangle as Koch curves
    DrawKochLine(hdc, x1, y1, x2, y2, depth);
    DrawKochLine(hdc, x2, y2, x3, y3, depth);
    DrawKochLine(hdc, x3, y3, x1, y1, depth);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Drawing the Koch snowflake
        double x1 = 100, y1 = 200;
        double x2 = 400, y2 = 200;
        int depth = 4;  // You can change this depth for more or less recursion
        DrawKochSnowflake(hdc, x1, y1, x2, y2, depth);

        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "KochSnowflakeWindow";

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Koch Snowflake",               // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
