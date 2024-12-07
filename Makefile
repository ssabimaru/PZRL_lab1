CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o utils.o
TARGET = main

# Основная цель
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Правило для main.o
main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

# Правило для utils.o
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

# Очистка
clean:
	rm -f $(OBJ) $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)