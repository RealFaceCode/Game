#define GLFW_INCLUDE_NONE
#include <core.h>
#include <logger.h>

int main() {
    LOG_INFO({}, "hello world");
    return 0;
}
