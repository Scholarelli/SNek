cmake_minimum_required(VERSION 3.30)
project(SNek)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(SNek main.cpp
        GameWindow.cpp
        GameWindow.h
        types.h
        SnakePlayfield.cpp
        SnakePlayfield.h
        Buffer.cpp
        Buffer.h
        DoubleBuffer.cpp
        DoubleBuffer.h
        controls.cpp
        controls.h
        UIAction.h
        Menu/MenuBase.cpp
        Menu/MenuBase.h
        Menu/PauseMenu.cpp
        Menu/PauseMenu.h
        Menu/MainMenu.cpp
        Menu/MainMenu.h
        WindowManager.cpp
        WindowManager.h



)
target_link_libraries(SNek ${CURSES_LIBRARIES})