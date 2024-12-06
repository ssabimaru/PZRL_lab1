#include <stdio.h>
#include <ctype.h>

int calculate(int left_operand, char operator, int right_operand){
    switch (operator)
    {
    case '+': return left_operand + right_operand;
    case '-': return left_operand - right_operand;
    case '*': return left_operand * right_operand;
    case '%': 
        if (right_operand ==0){
            printf("Ошибка: деление на ноль");
            return -1;
        }
        return left_operand % right_operand;
    default: return -1;
        break;
    }
}

// Проверяет, является ли строка числом
int is_number(const char *str) {
    if (*str == '-' || *str == '+') str++; // Пропускаем знак
    while (*str) {
        if (!isdigit(*str)) return 0; // Если не цифра, возвращаем ошибку
        str++;
    }
    return 1;
}