CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Iinclude/SDL3
LDFLAGS = -Llib -lSDL3 -lm
SRC = src/main.c sim/physics-engine.c sim/ball.c src/PID.c src/ui.c
OBJ = src/main.o sim/physics-engine.o sim/ball.o src/PID.o src/ui.o
TARGET = controller

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f src/*.o sim/*.o $(TARGET)

