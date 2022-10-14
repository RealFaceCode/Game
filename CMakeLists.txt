cmake_minimum_required(VERSION 3.19)
project(Game)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "hdr/*.hpp" "src/*.c" "hdr/*.h")

include_directories("vendor/Playground/PlaygroundLib/hdr")
include_directories("vendor/Playground/PlaygroundLib/vendor/glfw/include")
include_directories("vendor/Playground/PlaygroundLib/vendor/glad")
include_directories("vendor/Playground/PlaygroundLib/vendor/glm/glm")
include_directories("vendor/Playground/PlaygroundLib/vendor/fhandle")
include_directories("vendor/Playground/PlaygroundLib/vendor/stb")

add_executable(Game ${SOURCE_FILES} ${GLAD_FILES} ${FHANDLE_FILES} src/main.cpp)

add_subdirectory(vendor/Playground/PlaygroundLib)
target_link_libraries(Game PlaygroundLib)