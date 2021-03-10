CC=gcc
CFLAGS=
CLIBS=-lncurses
TARGET=./target
SRC=./src

build:
	$(CC) -o $(TARGET)/curse $(SRC)/main.c $(CFLAGS) $(CLIBS)

