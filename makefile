CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I src/include -I src/headers
LDFLAGS = -L src/lib -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2main

TARGET = game
SRC_DIR = src\Cfiles
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = src\obj
SRC_FILES += main.c
OBJ_FILES = $(patsubst $(SRC_DIR)\%.c, $(OBJ_DIR)\%.o, $(SRC_FILES))


all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	del $(OBJ_DIR)\*.o
