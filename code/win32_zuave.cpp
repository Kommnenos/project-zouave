#include <windows.h>

#define local_persist static
#define global_variable static
#define internal_function static

global_variable bool running;

LRESULT CALLBACK MainWindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam){

    LRESULT Result = 0;
    switch(Message){
        case WM_SIZE:{
            OutputDebugStringA("WM_SIZE\n");
        } break;
        case WM_DESTROY:{
            running = false;
        } break;
        case WM_CLOSE:{
            running = false;
        } break;
        case WM_ACTIVATEAPP:{
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;
        case WM_PAINT:{
            PAINTSTRUCT paint;
            HDC deviceConstruct = BeginPaint(Window, &paint);
            int height = paint.rcPaint.bottom - paint.rcPaint.top;
            int width = paint.rcPaint.right - paint.rcPaint.left;
            PatBlt(deviceConstruct, paint.rcPaint.left, paint.rcPaint.top, width, height, BLACKNESS);
            EndPaint(Window,  &paint);
        } break;
        default:{
            Result = DefWindowProc(Window, Message, WParam, LParam);
        } break;

    }

    return(Result);
}

/*hInstance = Handle of the executor
hPrevInstace = Legacy
pCmdLine = Command line that got set on run
nCmdShow = Normal, maximised or minimised (why tho)*/

int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode){

    /*UINT      style; The class style(s). This member can be any combination of the Class Styles.
    WNDPROC   lpfnWndProc; A pointer to the window procedure. You must use the CallWindowProc function to call the window procedure. For more information, see WindowProc.
    int       cbClsExtra; The number of extra bytes to allocate following the window-class structure. The system initializes the bytes to zero.
    int       cbWndExtra; The number of extra bytes to allocate following the window instance. The system initializes the bytes to zero. If an application uses WNDCLASS to register a dialog box created by using the CLASS directive in the resource file, it must set this member to DLGWINDOWEXTRA.
    HINSTANCE hInstance; A handle to the instance that contains the window procedure for the class.
    HICON     hIcon; A handle to the class icon. This member must be a handle to an icon resource. If this member is NULL, the system provides a default icon.
    HCURSOR   hCursor; A handle to the class cursor. This member must be a handle to a cursor resource. If this member is NULL, an application must explicitly set the cursor shape whenever the mouse moves into the application's window.
    HBRUSH    hbrBackground; A handle to the class background brush.
    LPCSTR    lpszMenuName; The resource name of the class menu, as the name appears in the resource file. If you use an integer to identify the menu, use the MAKEINTRESOURCE macro.
    LPCSTR    lpszClassName; A pointer to a null-terminated string or is an atom. If this parameter is an atom, it must be a class atom created by a previous call to the RegisterClass or RegisterClassEx function. The atom must be in the low-order word of lpszClassName; the high-order word must be zero.
     */

    WNDCLASS WindowClass = {};
    WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    WindowClass.lpfnWndProc = MainWindowCallback;
    WindowClass.hInstance = Instance;
    WindowClass.lpszClassName = "ProjectZouaveWindowClass";

    if(RegisterClass(&WindowClass)){
        HWND WindowHandle = CreateWindowEx(0, WindowClass.lpszClassName, "Project Zouave", WS_OVERLAPPEDWINDOW|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);
        if(WindowHandle){
            running = true;

            while(running){
                MSG message;
                BOOL messageResult = GetMessage(&message, 0, 0, 0);
                if (messageResult > 0){
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                } else {
                    break;
                }
            }

        } else {
            OutputDebugStringA("boop");
        }
    } else {
        OutputDebugStringA("boop");
    }


    return 0;

}
















