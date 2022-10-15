#include "../hdr/core.h"
#include <logger.h>
#include <util/memory.h>

void FunctionTest()
{
    LOG_INFO({C_HiLi("%s", ConsoleOutPutColor::Orange)}, "LOG TEST: %s", "Hello World!");

    {
        LOG_INFO({}, "MemoryTracking TEST");
        void* ptr = Malloc(8);
        MemoryPrintStack();
        Free(ptr);
    }
}