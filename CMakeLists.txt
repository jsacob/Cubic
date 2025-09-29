cmake_minimum_required(VERSION 3.10)
project(MyGLFWApp)

set(CMAKE_CXX_STANDARD 17)

# Use actual Homebrew GLFW path
include_directories(/opt/homebrew/opt/glfw/include)
link_directories(/opt/homebrew/opt/glfw/lib)

add_executable(app main.cpp)
target_link_libraries(app glfw)

# macOS frameworks
target_link_libraries(app
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

