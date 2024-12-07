#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(int left_operand, char calc_operator, int right_operand){
    switch (calc_operator)
    {
    case '+': return left_operand + right_operand;
    case '-': return left_operand - right_operand;
    case '*': return left_operand * right_operand;
    case '%': 
        if (right_operand ==0){
            printf("Error: division by zero\n"); // деление на ноль
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

void print_result_string(int *results, int res_cnt){
    printf("Result string: ");
    for(int i = 0; i < res_cnt; i++){
        char dec_char = (char)(results[i]);
        printf("%c", dec_char);
    }
    printf("\n");
}