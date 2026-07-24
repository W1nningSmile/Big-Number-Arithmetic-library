#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resize(char **arr, int *size) {
    char *temp = realloc(*arr, (*size));

    if (temp == NULL) {
        free(*arr);
        exit(1);
    }

    (*arr) = temp;
    //printf("pass");
}

char *get_line(int *len) {
    int size = 32;
    char *buffer = malloc(size);

    printf("enter: ");

    while (1){
        if (fgets(buffer+(*len), size-(*len), stdin) == NULL){
            break;
        } 

        (*len) = strlen(buffer);
    

        if ((*len) > 0 && buffer[(*len)-1] == '\n') break;

        size *= 2;

        resize(&buffer, &size);
    }
    buffer[strcspn(buffer, "\n")] = 0;

    printf("%s | %d | %d\n", buffer, size, (*len));

    return (buffer);
}

//chunk making

int expo(int power) {
    int temp = 1;
    for (int i = 0; i < power-1; i++) {
        temp *= 10;
    }
    return temp;
}

int *chunk_creation(int chunk_count, int *len, char *buffer) {
    int *arr = malloc(chunk_count*sizeof(int));

    for(int i = 0; i < chunk_count; i++) {
        int temp = 0;
        for (int j = 0; j < 9; j++){
            int str_index = i * 9 + j;

            if (str_index < (*len)) {
                temp = (temp * 10) + ((buffer)[str_index] - '0');

            } else {
                break;

            }
        }
        printf("temp is: %d\n", temp);
        arr[i] = temp;
    }

    if (chunk_count > 1) {
        int temp2 = 0;

        for (int i =0; i < ((*len)-1)%9; i++) {
            printf("%d\n", ((buffer)[i + 9*((*len)/9)] - '0') * expo((9-i)));
            temp2 += ((buffer)[i + 9*((*len)/9)] - '0') * expo(9-i);
            printf("T: %d\n", temp2);
        }
        printf("temp 2 is: %d\n", temp2);
        arr[chunk_count-1] = temp2;
    }
    

    for (int i = 0; i < chunk_count; i++){
        printf("the final chunk(s) are: %d\n", arr[i]);
    }

    printf("Your final array is: ");

    for (int i = 0; i < chunk_count-1; i++){
        printf("%d", arr[i]);
    }

    printf("%d", arr[chunk_count-1]/expo(9-((*len)-2)%9)); // -1 for \0 and another -1 bc expo increase power by 1

    return arr;
}