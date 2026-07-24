#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "func.h"



int main() {
    int len = 0;

    char *buffer = get_line(&len);

    int chunk_count = ((len-2) / 9)+1; //standard int can only have a max digit count of 9 for a number with only 9s in it 
    printf("chunk count: %d\n", chunk_count);

    int *arr = chunk_creation(chunk_count, &len, buffer);

}
