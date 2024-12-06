#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc < 5) {
        printf("Ошибка: недостаточно аргументов.\n");
        return 1;
    }
    // вывод массива

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    // поиск флага

    int key_index = -1;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-k") == 0) {
            key_index = i;
            break;
        }
    }
    // проверка флага

     if (key_index == -1 || key_index + 1 >= argc || !is_number(argv[key_index + 1])) {
        printf("Ошибка: некорректный или отсутствующий ключ дешифрования.\n");
        return 1;
    }

    int key = atoi(argv[key_index + 1]);

    // количество выражений

    int expression_count = (key_index - 1) / 3;
    if ((key_index - 1) % 3 != 0) {
        printf("Ошибка: некорректный формат выражений.\n");
        return 1;
    }


    
    int *results = malloc(expression_count * sizeof(int));
    if (!results) {
        printf("Ошибка: не удалось выделить память.\n");
        return 1;
    }


    for (int i = 0; i < 3; i++){
        int left_operand = atoi(argv[i * 3 + 1]);
        char operator = argv[i * 3 + 2][0];
        int right_operand = atoi(argv[i * 3 + 3]);
        int result = 0;

        switch (operator)
        {
        case '+': result = left_operand + right_operand; break;
        case '-': result = left_operand - right_operand; break;
        case '*': result = left_operand * right_operand; break;
        
        default:
            printf("invalid input ыыыы\n");
            return 1;
        }
        printf("answer %d\n", result);
    }


}