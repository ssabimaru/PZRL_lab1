#ifndef UTILS_H
#define UTILS_H

// Проверяет, является ли строка числом
int is_number(const char *str);

// Выполняет вычисление двух чисел с указанным оператором
int calculate(int left_operand, char calc_operator, int right_operand);

#endif