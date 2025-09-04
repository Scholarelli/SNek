# Makefile for SNek project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDFLAGS = -lncurses

# Project name
TARGET = SNek

# Source files
SOURCES = main.cpp \
          GameWindow.cpp \
          SnakePlayfield.cpp \
          Buffer.cpp \
          DoubleBuffer.cpp \
          controls.cpp \
          Menu/MenuBase.cpp \
          Menu/PauseMenu.cpp \
          Menu/MainMenu.cpp \
          Menu/GameOverMenu.cpp \
          Menu/LeaderboardMenu.cpp \
          WindowManager.cpp \
          SnakeMovement.cpp \
          Levels.cpp \
          LBscores.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all


# Mark targets that don't create files
.PHONY: all clean rebuild install uninstall