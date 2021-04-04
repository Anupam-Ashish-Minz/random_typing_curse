CC=gcc
CFLAGS=
CLIBS=-lncurses
TARGET=curse
OUT_DIR=target
SRC=./src
MKDIR_P=mkdir -p

build-debug:
	$(MKDIR_P) $(OUT_DIR)
	$(CC) -o $(OUT_DIR)/$(TARGET) $(SRC)/main.c $(CFLAGS) $(CLIBS) -g

build:
	$(MKDIR_P) $(OUT_DIR)
	$(CC) -o $(OUT_DIR)/$(TARGET) $(SRC)/main.c $(CFLAGS) $(CLIBS)
