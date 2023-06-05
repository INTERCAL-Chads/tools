#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../intercal.h"





int main(int argv, char** argc) {
    spot n = atoi(argc[1]);
    printf("%d\n", spot_and(n));


    return 0;
}