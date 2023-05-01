all: compile link 
compile:
	g++ -I src/include -c Main.cpp
link:
	g++ main.o -o Test -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio 