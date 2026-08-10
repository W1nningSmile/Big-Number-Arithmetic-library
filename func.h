#ifndef FUNC_H
#define FUNC_H

typedef struct {
    int len;
    int point_index;
    int chunk_count;

    char *buffer;
    int *arr;
} Big_int;

char *get_line(int *len);
int *chunk_creation(int len, char *buffer,  int *nbr_chunk);
Big_int *create(void);
Big_int *add(Big_int *num1, Big_int *num2);

//#define CREATE {malloc(sizeof(Big_int)), .len = 0} //<-- very neet trick (called "Macro Initializing": https://stackoverflow.com/questions/53847326/initializing-structure-using-macros)

#endif