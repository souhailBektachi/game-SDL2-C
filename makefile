CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I src/include
LDFLAGS = -L src/lib -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2main

TARGET = game
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
SRC += main.c
OBJ = $(SRC:.c=.o)

ASSETS_DIR = assets
ASSETS = $(wildcard $(ASSETS_DIR)/*)
ASSETS_C = $(ASSETS:%=%.o)

all: $(TARGET)

$(TARGET): $(OBJ) $(ASSETS_C)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(ASSETS_C) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ASSETS_C): $(ASSETS)
	$(foreach asset,$(ASSETS), \
		xxd -i $(asset) | sed -e "s/unsigned/const unsigned/g" -e "s/_len/_size/g" > $(asset).c; \
	)

clean:
	rm -f $(TARGET) $(OBJ) $(ASSETS_C)
