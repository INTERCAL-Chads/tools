#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argv, char** argc) {
    int num = atoi(argc[1]);
    int* result = double_dabble(num);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}