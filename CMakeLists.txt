cmake_minimum_required(VERSION 3.30)
project(SNek)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 20)

add_executable(SNek main.cpp
        GameWindow.cpp

        SnakePlayfield.cpp

        Buffer.cpp

        DoubleBuffer.cpp

        controls.cpp


        Menu/MenuBase.cpp

        Menu/PauseMenu.cpp

        Menu/MainMenu.cpp

        Menu/GameOverMenu.cpp

        Menu/LeaderboardMenu.cpp

        WindowManager.cpp


        SnakeMovement.cpp
        Levels.cpp
        Levels.h
        LBscores.cpp
        LBscores.h


)
#target_link_libraries(SNek ${CURSES_LIBRARIES})
target_link_libraries(SNek ${CURSES_LIBRARIES})
