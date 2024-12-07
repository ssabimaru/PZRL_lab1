#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if (argc < 4) {
        printf("Error: Not enough arguments.\n");
        return 1;
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
        printf("Error: Invalid or missing decryption key.\n"); // неправильный ключ или его отсутствие
        return 1;
    }

    int key = atoi(argv[key_index + 1]);

    // количество выражений

    int expression_count = (key_index - 1) / 3; // количество операций
    if ((key_index - 1) % 3 != 0) {
        printf("Error: incorrect expression format.\n"); // некорректный формат выражений.
        return 1;
    }


    
    int *results = malloc(expression_count * sizeof(int));
    if (!results) {
        printf("Error: Failed to allocate memory.\n"); // не удалось выделить память.
        return 1;
    }


    for (int i = 0; i < expression_count; i++){
        int left_operand = atoi(argv[i * 3 + 1]);
        char calc_operator = argv[i * 3 + 2][0];
        int right_operand = atoi(argv[i * 3 + 3]);


        int result = calculate(left_operand, calc_operator, right_operand);

        if (result == -1) {
            printf("Error: incorrect operator in expression #%d.\n", i + 1); // некорректный оператор в выражении .. 
            free(results);
            return 1;
        }

        results[i] = result - key; // Дешифруем результат
        printf("Answer #%d: %d\n", i + 1, result);
    }

    print_result_string(results, expression_count);

    free(results);
    return 0;
}