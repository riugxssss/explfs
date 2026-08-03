CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = explfs

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
