CXX = g++
CXXFLAGS = -Wall -Werror -pedantic -std=c++11
TARGET = Test
LIBS = -lsfml-window -lsfml-system -lsfml-graphics

$(TARGET): Main.cpp
    $(CXX) $(CXXFLAGS) -o $(TARGET) Main.cpp $(LIBS)