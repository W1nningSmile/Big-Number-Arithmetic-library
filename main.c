#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void format(char *main, char *side, int *i_p, int *j_p); //rework it hard
void big_add(char *main, char *side);
void setter_front(char *main, char *side,int i_p, int j_p);
void initialize(char **i, char **j, char *arr_main, char *arr_buffer);
int find_dot_index(char *target);


int main () {
    char i[] = "123"; //put numbers here
    char j[] = ".877";

    char *pi = i;
    char *pj = j;

    char arr_main[N+1] = {0};
    char arr_buffer[N+1] = {0};

    initialize(&pi, &pj, arr_main, arr_buffer); 

    printf("\nmain: %s\nbuffer: %s", pi, pj);

    big_add(pj, pi);
}

void format(char *main, char *side, int *i_p, int *j_p) {
    int i = strlen(main)-1;
    int j = strlen(side)-1;
    int after_main;
    int after_side;
    int diff_deci;
    int diff_unit;


    *i_p = find_dot_index(main); //finds index of decimal for main
    *j_p = find_dot_index(side); //finds index of decimal for side

    after_main = strlen(main) - *i_p -1;
    after_side = strlen(side) -*j_p -1;
    diff_deci = after_main - after_side; //gives diff in decimal numbers
    diff_unit = *i_p-*j_p; //gives diff in numbers before decimal


    if (after_side < after_main) {
        int new_len = *j_p + 1 + after_main; //check index of new dot
        for (int x = after_side; x < after_main; x++) {
            side[*j_p + 1 + x] = '0'; 
        }
        side[new_len] = '\0';
    } else if (after_side > after_main) {
        int new_len = *i_p + 1 + after_side; //check index of new dot
        for (int x = after_main; x < after_side; x++) {
            main[*i_p + 1 + x] = '0'; 
        }
        main[new_len] = '\0';
    }

    setter_front(main, side, *i_p, *j_p);

    printf("Formating done");
        
    

    //make a for loop going from i = decimal place to 0 and doing basic addition 
}


void big_add(char *main, char *side) {
    int sum = 0;
    char temp[N] = {0};
    int len = strlen(main);
    int temp_nbr;
    int i_p;
    int j_p;

    i_p = find_dot_index(main); //finds index of decimal for main
    j_p = find_dot_index(side); //finds index of decimal for side (from reverse number)
    printf("\ni_p : %d\nj_p : %d\n", i_p, j_p);


    for (int i = len; i >= 0; i--) {
        printf("\n%c || %c\n", main[i], side[i]);
        if (i != i_p){
            sum = (main[i]-'0') + (side[i]-'0') + temp[i];
            printf("SUMSUM: %d\ntemp[i] = %c\n\n%c + %c", sum, temp[i], main[i]-'0', side[i]-'0');
            if (sum > 9) {
                temp_nbr =  sum/10; //remove this later
                temp[i-1] += temp_nbr; 
                temp[i] = sum%10 + '0';
                printf("\n\ntemp_nbr: %d | sum: %d | temp[i+1] : %c | temp[i] : %c\n\n",
                     temp_nbr, sum, temp[i+1], temp[i]);
            } else {
                temp[i] = sum+'0';
            }
        } else { //dot logic
            temp[i-1] = (temp[i]);
            temp[i] = '.';
        }

    }
    temp[len] = '\0';
    printf("\n\ntemp: %s", temp);
}

void setter_front(char *main, char *side,int i_p, int j_p) {
    int diff = i_p - j_p; // if value positive, i_p bigger

    if (diff > 0) { //i_p + 1 and j_p + diff + 1 ->shifts right
        int len =strlen(side);
        printf("len : %d", diff);
        memmove(side+diff, side, len +1); //+1 is for \0

        for (int i =0; i < diff; i++) {
            side[i] = '0';
        }
    } else if (diff < 0) { //i_p + diff + 1 and j_p + 1 ->shifts left
        int len =strlen(main);
        diff = -diff;
        memmove(main+diff, main, len +1); //+1 is for \0

        for (int i =0; i < diff+1; i++) {
            main[i] = '0';
        }
    }

    int len_main = strlen(main);
    int len_side = strlen(side);

    memmove(main+1,main, len_main+1);
    memmove(side+1,side,len_side+1);

    main[0] = '0';
    side[0] = '0'; //need to add extra buffer just in case. otherwise may overflow
    printf("\n\n\n\n\n\n%s\n%s\n\n", main, side);
}

void initialize(char **i, char **j,  char *arr_main, char *arr_buffer) {
    //char arr_main[N+1] = {0};
    //char arr_buffer[N+1] = {0};

    int i_p;
    int j_p;

    int main_len;
    int buff_len;

    //char i[] = "1231.99328743982749825";
    //char j[] = "9000.3456832942837432";

    strncpy(arr_main, *i, N-1);
    strncpy(arr_buffer, *j, N-1);

    main_len = strlen(arr_main);
    buff_len = strlen(arr_buffer);

    if (main_len >= buff_len) {
        format(arr_main,arr_buffer, &i_p, &j_p);
    } else if (main_len < buff_len) {
        format(arr_buffer,arr_main, &j_p, &i_p);
    }

    *i = arr_main; 
    *j = arr_buffer;
    printf("\n\nstring transfer: %s\n%s\n\nstring transfer2: %s\n%s\n\n", arr_main, i, arr_buffer, j);
}

int find_dot_index(char *target) {
    int p;
    int i = strlen(target)-1;

    for (int y =0; y <= i; y++){ //finds index of decimal for main
        printf("%d\n", y);
        if (target[y] == '.') {
            return y;
        }

    }
    target[i+1] = '.';
    return (i+1);
}