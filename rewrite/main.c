#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "func.h"

int expo(int power);

int main() {
    int len = 0;

    char *buffer = get_line(&len);

    int chunk_count = ((len-1) / 9)+1; //standard int can only have a max digit count of 9 for a number with only 9s in it 
    printf("chunk count: %d\n", chunk_count);

    int arr[chunk_count];

    for(int i = 0; i < chunk_count-1; i++) {
        int temp = 0;
        for (int j = 0; j < 9; j++){
            int str_index = i * 9 + j;

            if (str_index < len) {
                temp = (temp * 10) + (buffer[str_index] - '0');

            } else {
                break;

            }
        }
        printf("temp is: %d\n", temp);
        arr[i] = temp;
    }

    int temp2 = 0;

    for (int i =0; i < len%9-1; i++) {
        printf("%d\n", (buffer[i + 9*(len/9)] - '0') * expo(9 - i));
        temp2 += (buffer[i + 9*(len/9)] - '0') * expo(9 - i);
    }
    printf("temp 2 is: %d\n", temp2);
    arr[chunk_count-1] = temp2;

    if (temp2 == 0) {
        chunk_count--; //weird bug where inputs like 0, 9, 18, etc.. create an extra chunk --> **temp fix. Find reason as to why soon**
    }

    for (int i = 0; i < chunk_count; i++){
        printf("the final array is: %d\n", arr[i]);
    }
}

int expo(int power) {
    int temp = 1;
    for (int i = 0; i < power-1; i++) {
        temp *= 10;
    }
    return temp;
}