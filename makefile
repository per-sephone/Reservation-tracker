CC = g++
CFLAGS = -std=c++17 -g -Wall
VFLAGS = --leak-check=full
SOURCES = reservation.cpp main.cpp manager.cpp
EXE = main

main:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXE)

clean:
	rm $(EXE)

memch:	
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXE)
	valgrind $(VFLAGS) $(EXE)
