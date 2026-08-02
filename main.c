#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "func.h"



int main() {
    int len = 0;

    char *buffer = get_line(&len);
     //standard int can only have a max digit count of 9 for a number with only 9s in it 

    int *arr = chunk_creation(len, buffer);

}
