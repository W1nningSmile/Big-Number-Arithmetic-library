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

