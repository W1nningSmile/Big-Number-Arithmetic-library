#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Big_int* create(void) {
    Big_int *ptr = malloc(sizeof(Big_int));

    if (ptr != NULL) {
        ptr->len = 0;
        ptr->point_index = 0;
        ptr->chunk_count = 0;
        ptr->is_negative = 1;

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

char *get_line(int *len, int *neg) {
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
    printf("%c", buffer[0]);

    if (buffer[0] == '-') {
        *neg *= -1;
        (buffer)[0] = '0';
    }

    return (buffer);
}

//chunk making

int *chunk_creation(int len, char *buffer, int *nbr_chunk) {
    int chunk_count = ((len-2) / 9)+1; //very risky -> later make it guarenteed rather than an assumption
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

void align_chunks(Big_int *num1, Big_int *num2) { //takes 2 big_int and adds empty chunks to the smaller one so both numbers have equal chunk amounts
    //align_chunk ensures that:
    //1. both numbers have the same amount of chunks
    //2. both numbers recieve an extra chunk as padding(need to increase the padding for mulitplication though)

    int len_diff = ((num1)->chunk_count)-((num2)->chunk_count);

    if (len_diff > 0) {
        (num2)->arr = resize_int((num2)->arr, ((num1)->chunk_count)*sizeof(*(num2)->arr));
        printf("H: %d, %d, %d\n", (num2)->len, ((num2)->len) * sizeof(int), len_diff);
        //memmove(&(num2->arr)[len_diff], &(num2->arr)[0], sizeof(int)*num2->chunk_count);

        for (int i = 0; i < len_diff; i++) {
            ((num2)->arr)[(num2)->chunk_count + i] = 0;
        }

        (num2)->chunk_count += len_diff;
    } else if (len_diff < 0) {
        (num1)->arr = resize_int((num1)->arr, ((num2)->chunk_count)*sizeof(*(num2)->arr));
        //memmove(&(num1->arr)[-len_diff], &(num1->arr)[0], sizeof(int)*num1->chunk_count);

        for (int i = 0; i < -len_diff; i++) {
            ((num1)->arr)[(num1)->chunk_count + i] = 0;
        }

        (num1)->chunk_count -= len_diff;
    } 

    if (num1->chunk_count <= ((num1->len)-1)/9 + 1 && num2->chunk_count <= ((num1->len)-1)/9 + 1) {
        (num1)->arr = resize_int((num1)->arr, ((num2)->chunk_count)*sizeof(*(num2)->arr));
        (num2)->arr = resize_int((num2)->arr, ((num1)->chunk_count)*sizeof(*(num2)->arr));

        for (int i = 0; i < 1; i++) {
            ((num1)->arr)[(num1)->chunk_count + i] = 0;
            ((num2)->arr)[(num2)->chunk_count + i] = 0;
        }

        (num2)->chunk_count += 1;
        (num1)->chunk_count += 1;
    }
    
    
    
    printf("done\n");
}

Big_int *add(Big_int *num1, Big_int *num2) {
    align_chunks(num1, num2);

    for (int i = 0; i < num2->chunk_count; i++) {
        printf("hgggi: %d (%d), %d (%d)\n", (num2->arr)[i], num2->chunk_count, (num1->arr)[i], num1->chunk_count); 
    }

    int *sum = malloc(num1->chunk_count * sizeof(*sum)); //keep big variables on heap for more storage

    if (sum == NULL) {
        printf("\n\nOut of memory.");
        exit(1); //find a better solution for when these things fail
    }
    int carry = 0;

    for (int i =0; i< num1->chunk_count; i++) {
        unsigned long long int temp_sum = 0; //use same thing for multiplication 
        temp_sum = (num1->arr)[i] + (num2->arr)[i] + carry;

        carry = temp_sum / 1000000000;
        sum[i] = temp_sum % 1000000000;
        printf("sum(%d) is %d | temp_sum %llu | carry %d\n", i, sum[i], temp_sum, carry);
    }

    printf("sum: %d", sum[num1->chunk_count-1]);
    for (int i = num1->chunk_count-2; i >= 0; i--) {
        printf(" | %09d", sum[i]); //neat trick that forces padding with leading zeros (https://stackoverflow.com/questions/33323384/printing-0-as-000-in-c-i-e-print-decimal-to-3-digit)
    }

}

Big_int *sub(Big_int *num1, Big_int *num2) { //make this simpler -> retouch the logic to try and decrease the amount of instructions needed 
    align_chunks(num1, num2);

    for (int i = 0; i < num2->chunk_count; i++) {
        printf("hgggi: %d (%d), %d (%d)\n", (num2->arr)[i], num2->chunk_count, (num1->arr)[i], num1->chunk_count); 
    }

    int *sum = malloc(num1->chunk_count * sizeof(*sum)); //keep big variables on heap for more storage

    if (sum == NULL) {
        printf("\n\nOut of memory.");
        exit(1); //find a better solution for when these things fail
    }

    Big_int *big = NULL;
    Big_int *small = NULL;

    printf("yoyoyo %d vs %d\n", (num1->arr)[num1->chunk_count -2], (num2->arr)[num2->chunk_count -2]);

    if ((num1->arr)[num1->chunk_count -2] * (num1->is_negative) >= (num2->arr)[num2->chunk_count -2] * (num2->is_negative)) {
        big = num1;
        small = num2;
        small->is_negative *= -1;
    } else {
        big = num2;
        small = num1;
        big->is_negative *= -1;
        //sum->is_negative = 1; here or smt like that for negative numbers
    }

    printf("cro %d vs %d\n", (big->arr)[big->chunk_count -2], (small->arr)[small->chunk_count -2]);

    int carry = 0;
    int sign = 1*big->is_negative;
    printf("big is negative: %d vs small is negative: %d\n", big->is_negative, small->is_negative);

    for (int i =0; i < num1->chunk_count; i++) {
        long long int temp_sum = 0; //use same thing for multiplication 
        temp_sum = (big->arr)[i] * (big->is_negative) + (small->arr)[i] * (small->is_negative) - carry;
        printf("big: %d vs small: %d vs %d vs %lld\n", (big->arr)[i], (small->arr)[i], carry, temp_sum);

        if (temp_sum < 0 && (big->arr)[i+1] > 0) {
            temp_sum += 1000000000;
            carry = 1;
        } else if (temp_sum > 999999999){
            temp_sum -= 1000000000;
            carry=-1;
        }else{
            carry = 0;
        }

        if (temp_sum < 0) {
            temp_sum *= -1;
        }

        printf("%d vs %d vs %d vs %lld\n", (big->arr)[i], (small->arr)[i], carry, temp_sum);

        sum[i] = temp_sum;
        printf("sum(%d) is %d | temp_sum %d | carry %d\n\n", i, sum[i], temp_sum, carry);
    }
 
    
    printf("number is_negative = %d\n", sign);
    printf("sum: %d", sum[num1->chunk_count-1]);
    for (int i = num1->chunk_count-2; i >= 0; i--) {
        printf(" | %09d", sum[i]); //neat trick that forces padding with leading zeros (https://stackoverflow.com/questions/33323384/printing-0-as-000-in-c-i-e-print-decimal-to-3-digit)
    }

}