CXX = g++
CXX_FLAGS = -Wall -Werror -pedantic -std=c++11
TARGET = Game
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
SRCS = Main.cpp

ifeq ($(OS),Windows_NT)
	TARGET = Game.exe
endif

$(TARGET):
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(SRCS) $(LIBS)
