#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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

    if (arr == NULL) {
        printf("\n\nOut of memory.");
        exit();
    }

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

int *chunk_creation(int len, char *buffer) {
    int chunk_count = ((len-2) / 9)+1;
    int *arr = malloc(chunk_count*sizeof(buffer));

    if (arr == NULL) {
        printf("\n\nOut of memory.");
        exit();
    }

    int index = len -2;
    int chunk_index = 0;

    while (index >= 0) {
        int chunk = 0;
        int mult = 1;

        for (int i = 0; i < 9 && index >= 0; i++) {
            chunk += (buffer[index] - '0') * mult;

            mult *= 10;
            index--;
            printf("%d\n", chunk);
        }
        arr[chunk_index] = chunk;
        chunk_index++;
    }

    for (int i = 0; i < chunk_count; i++) {
        printf("yp: %d\n", arr[i]);
    }


}