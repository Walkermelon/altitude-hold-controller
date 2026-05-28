CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iinclude/SDL3
LDFLAGS = -Llib -lSDL3
SRC = src/main.c
OBJ = src/main.o
TARGET = controller

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	del /f src\*.o $(TARGET).exe