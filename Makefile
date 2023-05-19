CXX = g++
CXX_FLAGS = -Wall -pedantic -std=c++11 -Isrc/include/
TARGET = Game
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
SRCS = Main.cpp

ifeq ($(OS),Windows_NT)
	LIBS := -Lsrc/lib/ $(LIBS)
	TARGET = Game.exe
endif
ifeq ($(OS),Darwin)
	LIBS := -Lsrc/LibMac/ $(LIBS)
endif

$(TARGET):
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(SRCS) $(LIBS)

all: $(TARGET)

 
   
