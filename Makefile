CFLAGS = -g -Wall

test: main.cpp dslist.h
	g++ main.cpp $(CFLAGS) -o test.exe
