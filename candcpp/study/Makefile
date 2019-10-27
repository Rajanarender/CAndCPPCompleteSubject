
#Color coding:
#Targets,
#flags
CC = g++
CFLAGS = -c -Wall
all: stringClass

stringClass: stringClass.o
	$(CC) stringClass.o -o stringClass #tab is must

stringClass.o: stringClass.cpp
	$(CC) $(CFLAGS) stringClass.cpp
clean:
	rm -rf *.o stringClass

