# Target library
CC=g++
TARGET=example.x
CFLAGS=-Wall
SRC=example.cpp numstr.cpp

all:
	$(CC) $(CFLAGS)  $(SRC) -o $(TARGET)

clean: 
	rm $(TARGET)
