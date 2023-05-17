CXX = g++
CXX_FLAGS = -Wall -pedantic -std=c++11 -Isrc/include/
TARGET = Game
LIBSs = -lsfml-window -lsfml-system -lsfml-graphics
SRCS = Main.cpp

ifeq ($(OS),Windows_NT)
	LIBS := -Lsrc/lib/ $(LIBSs)
	TARGET = Game.exe
endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CCFLAGS += -D LINUX
	LIBS := -Lsrc/LibLinux/ $(LIBSs)
endif
ifeq ($(UNAME_S),Darwin)
    CCFLAGS += -D OSX
	LIBS := -Lsrc/libMac/ $(LIBSs)
endif

$(TARGET):
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(SRCS) $(LIBS)

all: $(TARGET)
