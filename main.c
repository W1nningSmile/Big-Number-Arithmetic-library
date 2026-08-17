#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void test();
void test2();

int main() {
    test2();
}

void test() {
    Big_int *num = create();

    num->buffer = get_line(&(num->len));
     //standard int can only have a max digit count of 9 for a number with only 9s in it 

    int *arr = chunk_creation(num->len, num->buffer, &(num->chunk_count));
    printf("chunk count: %d", num->chunk_count);
}

void test2() {

    Big_int *num = create();

    num->buffer = get_line(&(num->len));
     //standard int can only have a max digit count of 9 for a number with only 9s in it 

    num->arr = chunk_creation(num->len, num->buffer, &num->chunk_count);

    Big_int *num2 = create();

    num2->buffer = get_line(&(num2->len));
     //standard int can only have a max digit count of 9 for a number with only 9s in it 

    num2->arr = chunk_creation(num2->len, num2->buffer, &num2->chunk_count);

    printf("here\n");
    sub(num, num2);
    printf("\n");

    //for (int i =0; i < num2->chunk_count; i++) {
    //    printf("%d  ", (num2->arr)[i]);
    //}

}