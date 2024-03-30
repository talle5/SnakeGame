TARGET=SnakeGame
CC=g++
WARN=-Wall
STD=-std=c++23
MODULES=-fmodules-ts
OPT=-O3 $(STD) $(MODULES)
CCFLAGS=$(OPT) $(WARN) -pipe
LD=g++
LDFLAGS=-lraylib
OBJS=square.o rand.o screen.o game.o pause.o gameover.o playgame.o main.o

all: modules $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
 
main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o main.o
 
playgame.o: src/playgame.cpp
	$(CC) -c $(CCFLAGS) src/playgame.cpp -o playgame.o

square.o: src/square.cpp
	$(CC) -c $(CCFLAGS) src/square.cpp -o square.o

rand.o: src/rand.cpp
	$(CC) -c $(CCFLAGS) src/rand.cpp -o rand.o

pause.o: src/pause.cpp
	$(CC) -c $(CCFLAGS) src/pause.cpp -o pause.o

gameover.o: src/gameover.cpp
	$(CC) -c $(CCFLAGS) src/gameover.cpp -o gameover.o

screen.o: src/screen.cpp
	$(CC) -c $(CCFLAGS) src/screen.cpp -o screen.o

game.o: src/game.cpp
	$(CC) -c $(CCFLAGS) src/game.cpp -o game.o

modules:
	g++ $(OPT) -c -x c++-system-header thread
	g++ $(OPT) -c -x c++-system-header list
	g++ $(OPT) -c -x c++-system-header stack
	g++ $(OPT) -c -x c++-system-header random
	g++ $(OPT) -c -x c++-system-header raylib.h
	g++ $(OPT) -c -x c++-system-header rlgl.h

clean:
	rm -rf *.o gcm.cache