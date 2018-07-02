CFLAGS = -g -Wall -m32

test: main.cpp dslist.h
	g++ main.cpp $(CFLAGS) -o test.exe
