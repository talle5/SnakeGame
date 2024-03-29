TARGET=SnakeGame
CC=g++
WARN=-Wall
STD=-std=c++23
MODULES=-fmodules-ts
OPT=-O3 $(STD) $(MODULES)
CCFLAGS=$(OPT) $(WARN) -pipe
LD=g++
LDFLAGS=-lraylib
OBJS=square.o playgame.o main.o

all: modules $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
 
main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o main.o
 
playgame.o: src/playgame.cpp
	$(CC) -c $(CCFLAGS) src/playgame.cpp -o playgame.o

square.o: src/square.cpp
	$(CC) -c $(CCFLAGS) src/square.cpp -o square.o

modules:
	g++ $(OPT) -c -x c++-system-header thread
	g++ $(OPT) -c -x c++-system-header list
	g++ $(OPT) -c -x c++-system-header raylib.h
	g++ $(OPT) -c -x c++-system-header rlgl.h

clean:
	rm -rf *.o gcm.cache