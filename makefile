TARGET=hello-world
CC=g++
DEBUG=-g
OPT=-O3
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS= -lraylib
OBJS= main.o playgame.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
 
main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o main.o
 
playgame.o: src/playgame.cpp
	$(CC) -c $(CCFLAGS) src/playgame.cpp  -o playgame.o

square.o: src/square.cpp
	$(CC) -c $(CCFLAGS) src/square.cpp  -o square.o
 
clean:
	rm -f *.o
