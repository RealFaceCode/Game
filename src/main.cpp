#include <core.h>
#include <logger.h>
#include <window/window.h>
#include <window/input.h>
#include <util/hotloader.h>
#include <util/memory.h>

#include "../hdr/core.h"

/*  Using util Memory <util/memory>
 *
 *  DEFINE                  FUNCTION
 *                          void    MemoryEnableTracking(const bool& track);                                        <- Enable/Disable Tracking
 *  Malloc(bytes)           void*   MemoryMalloc(size_t bytes, const char* file, const int& line);                  <- Allocate memory
 *  Realloca(buffer, bytes) void*   MemoryRealloc(void* buffer, size_t bytes, const char* file, const int& line);   <- Reallocate memory
 *  MemReg(buffer)          void*   MemoryRegister(void* buffer, const char* file, const int& line);                <- add pointers to track
 *  MemDeReg(buffer)        void*   MemoryDeRegister(void* buffer);                                                 <- remove pointers from tacking
 *  MemZero(buffer, bytes)  void    MemoryZero(void* buffer, size_t bytes);                                         <- zero memory
 *  Free(buffer)            void    MemoryFree(void* buffer);                                                       <- delete memory and remove from tracking
 *                          bool    MemoryPrintStack();                                                             <- prints tracked memory addresses
 */

int main(int argv, const char** argc)
{
    {
        CoreInit();
        Window::Init();
    }

    MemoryEnableTracking(true);

    FUNC_TEST

    Window::Window window = Window::WindowBuilder
            .centerWindowOnScreen()
            .setSize(900, 600)
            .setOpenGLVersion(4, 6)
            .setRefreshRate(60)
            .setSettingsFileName("winSettings.node")
            .build("Game");

    window.init();

    {
        Input::SetSetting(Input::CollectKeyCallback, true);
        Input::SetSetting(Input::CollectCharacterCallback, true);
        Input::SetSetting(Input::CollectCursorPositionCallback, true);
        Input::SetSetting(Input::CollectCursorEnterCallback, true);
        Input::SetSetting(Input::CollectMouseButtonCallback, true);
        Input::SetSetting(Input::CollectScrollCallback, true);
        Input::SetSetting(Input::CollectDropCallback, true);
        Input::SetSetting(Input::CollectCharModsCallback, true);
        Input::SetSetting(Input::CollectFramebufferSizeCallback, true);
        Input::SetSetting(Input::CollectJoystickCallback, true);
        Input::SetSetting(Input::CollectMonitorCallback, true);
        Input::SetSetting(Input::CollectWindowContentScaleCallback, true);
        Input::SetSetting(Input::CollectWindowCloseCallback, true);
        Input::SetSetting(Input::CollectWindowFocusCallback, true);
        Input::SetSetting(Input::CollectWindowMaximizeCallback, true);
        Input::SetSetting(Input::CollectWindowPosCallback, true);
        Input::SetSetting(Input::CollectWindowRefreshCallback, true);
        Input::SetSetting(Input::CollectWindowSizeCallback, true);
        Input::SetSetting(Input::CollectWindowIconifyCallback, true);
        Input::SetSetting(Input::LoadDropedFiles, true);

        Input::SetFileEndingToWhitelist(".txt");
        Input::SetFileEndingToWhitelist(".node");
    }

    glViewport(0, 0, 900, 600);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    while(window.isWindowValid())
    {
        if(Input::IsKeyPressed(GLFW_KEY_ESCAPE))
        {
            window.close();
        }

        Input::Update();
        window.swapBuffers();
        Window::pollEvents();
        HotLoader::CheckFiles();
    }

    window.clear();

    if(MemoryPrintStack())
    {
        LOG_ASSERT(true, {}, "FIX ME!");
    }

    return 0;
}