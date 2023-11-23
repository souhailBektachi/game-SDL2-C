CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I src/include -I src/headers
LDFLAGS = -L src/lib -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2main

TARGET = game
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
SRC += main.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
