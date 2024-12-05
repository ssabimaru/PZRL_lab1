#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
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
            printf("invalid input\n");
            result = 0;
            return 1;
        }
        printf("answer %d\n", result);
    }
}