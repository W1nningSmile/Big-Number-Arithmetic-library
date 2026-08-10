#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Big_int* create(void) {
    Big_int *ptr = malloc(sizeof(Big_int));

    if (ptr != NULL) {
        ptr->len = 0;
        ptr->point_index = 0;
        ptr->chunk_count = 0;

        ptr->buffer = NULL;
        ptr->arr = NULL;
    }
    return ptr;
}

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

    if (buffer == NULL) {
        printf("\n\nOut of memory.");
        exit(1);
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

int *chunk_creation(int len, char *buffer, int *nbr_chunk) {
    int chunk_count = ((len-2) / 9)+1;
    int *arr = malloc(chunk_count*sizeof(int));

    if (arr == NULL) {
        printf("\n\nOut of memory.");
        exit(1);
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
    *nbr_chunk = chunk_count;
    printf("%d vs %d\n", *nbr_chunk, chunk_count);

    for (int i = 0; i < chunk_count; i++) {
        printf("yp: %d\n", arr[i]);
    }

    return arr;
}

int *resize_int(int *arr, int size) {
    int *temp = realloc(arr, size);

    if (temp == NULL) {
        free(arr);
        exit(1);
    }

    return temp;
}

Big_int *add(Big_int *num1, Big_int *num2) {
    int len_diff = (num1->chunk_count)-(num2->chunk_count);
    printf("predone, %d | %d vs %d\n", len_diff, num1->chunk_count, num2->chunk_count);

    printf("num1 arr: %p\n", (void *)num1->arr);
    printf("num2 arr: %p\n", (void *)num2->arr);
    printf("size: %zu\n", num2->len * sizeof(*num2->arr));

    if (len_diff > 0) {
        num2->arr = resize_int(num2->arr, (num1->len)*sizeof(*num2->arr));
        printf("H: %d, %d, %d\n", num2->len, (num2->len) * sizeof(int), len_diff);
        //memmove(&(num2->arr)[len_diff], &(num2->arr)[0], sizeof(int)*num2->chunk_count);

        for (int i = 0; i < len_diff; i++) {
            (num2->arr)[num2->chunk_count + i] = 0;
        }

        for (int i = 0; i < num1->chunk_count; i++) {
            printf("hi: %d, %d\n", (num1->arr)[i], (num2->arr)[i]);
        }
    } else if (len_diff < 0) {
        num1->arr = resize_int(num1->arr, (num2->len)*sizeof(*num2->arr));
        //memmove(&(num1->arr)[-len_diff], &(num1->arr)[0], sizeof(int)*num1->chunk_count);

        for (int i = 0; i < len_diff; i++) {
            (num1->arr)[num1->chunk_count + i] = 0;
        }

        for (int i = 0; i < num2->chunk_count; i++) {
            printf("hi: %d, %d\n", (num1->arr)[i], (num2->arr)[i]);
        }
    } else {
        
    }
    printf("done\n");

}