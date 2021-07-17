#include "window.h"
#include <Windows.h>
#include <string>
using namespace std;

Window* window = nullptr;

Window::Window() {

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_CREATE: {
            //Case when window create
            window->setHWND(hwnd);
            window->onCreate();
            break;
        }
        case WM_DESTROY: {
            //Case when window destroyed
            ::PostQuitMessage(0);
            window->onDestroy();
            break;
        }
        default: 
            return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return NULL;
};

bool Window::init() {
    //Window class info
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = L"WindowClass";
    wc.lpszMenuName = L"";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;
    if(!::RegisterClassEx(&wc)) return false;

    if (!window) window = this;

    //Window Creation
    m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass", L"3D Engine App", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);
    if (!m_hwnd) return false;
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);

    //Used to check that window is running
    m_is_run = true; 
    return true;
}

bool Window::broadcast() {
    MSG msg;
    window->onUpdate();
    while (::PeekMessage(&msg,NULL,0,0,PM_REMOVE) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    Sleep(0);
    return true; 
}

bool Window::release() {
    //Destroy window
    if (!::DestroyWindow(m_hwnd)) return false;
        
    return true;
}

bool Window::isRun()
{
    return m_is_run;
}

void Window::setHWND(HWND hwnd)
{
    this->m_hwnd = hwnd; 
}

RECT Window::getClientWindowRect()
{
    RECT rc;
    ::GetClientRect(this->m_hwnd, &rc);
    return rc;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
    m_is_run = false; 
}
