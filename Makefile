CC=gcc
CFLAGS=
CLIBS=-lncurses
DEBUG_FLAGS=-g
TARGET=curse
OUT_DIR=target
SRC=./src
MKDIR_P=mkdir -p

debug:
	$(MKDIR_P) $(OUT_DIR)
	$(CC) -o $(OUT_DIR)/$(TARGET) $(SRC)/main.c $(CFLAGS) $(CLIBS) $(DEBUG_FLAGS)

build:
	$(MKDIR_P) $(OUT_DIR)
	$(CC) -o $(OUT_DIR)/$(TARGET) $(SRC)/main.c $(CFLAGS) $(CLIBS)
