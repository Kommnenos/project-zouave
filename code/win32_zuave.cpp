
#include <windows.h>

/*hInstance = Handle of the executor
hPrevInstace = Legacy
pCmdLine = Command line that got set on run
nCmdShow = Normal, maximised or minimised*/

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow){
    
    MessageBoxA(0, "OwO", "uwu", MB_OK|MB_ICONINFORMATION);
    return 0;

}



