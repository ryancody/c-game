BUILD_DIR = build

ifeq ($(OS),Windows_NT)
    CC = /ucrt64/bin/gcc
    CFLAGS = -Wall -Wextra -g -std=c11 -I/ucrt64/include
    LIBS = -lraylib -lm -L/ucrt64/lib
    TARGET = $(BUILD_DIR)/main.exe
    SRC = src/main.c src/platform.c src/player.c
else
    CC = gcc
    CFLAGS = -Wall -Wextra -g -std=c11
    LIBS = -lraylib -lm
    TARGET = $(BUILD_DIR)/main
    SRC = $(wildcard src/*.c)
endif

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -rf $(BUILD_DIR)
