#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

void format(char *main, char *side, int *i_p, int *j_p); //rework it hard
void inverse(char *target); //fixed it. works well now
void big_add(char *main, char *side,int i_p, int j_p);
void setter_front(char *main, char *side,int i_p, int j_p);

//need to invert numbers


int main () {
    char arr_main[N+1] = {0};
    char arr_buffer[N+1] = {0};
    char i[] = "1231.99328743982749825";
    char j[] = "9000.3456832942837432";
    int i_p;
    int j_p;

    int main_len;
    int buff_len;

    strncpy(arr_main, i, N-1);
    strncpy(arr_buffer, j, N-1);

    main_len = strlen(arr_main);
    buff_len = strlen(arr_buffer);


    if (main_len >= buff_len) {
        format(arr_main,arr_buffer, &i_p, &j_p);
    } else if (main_len < buff_len) {
        format(arr_buffer,arr_main, &j_p, &i_p);
    }

    printf("\nmain: %s\nbuffer: %s", arr_main, arr_buffer);

    big_add(arr_main, arr_buffer, i_p, j_p);
}

void format(char *main, char *side, int *i_p, int *j_p) {
    int i = strlen(main)-1;
    int j = strlen(side)-1;
    int after_main;
    int after_side;
    int diff_deci;
    int diff_unit;


    

    for (int y =0; y <= i; y++){ //finds index of decimal for main
        printf("%d\n", y);
        if (main[y] == '.') {
            *i_p = y;
            break;
        }
    }

    for (int z= 0; z <= j; z++) { //finds index of decimal for side
        if (side[z] == '.') {
            *j_p = z;
            break;
        }
    }

    after_main = strlen(main) - *i_p -1;
    after_side = strlen(side) -*j_p -1;
    diff_deci = after_main - after_side; //gives diff in decimal numbers
    diff_unit = *i_p-*j_p; //gives diff in numbers before decimal


    for (int x = 0; x < N; x++) {
        if (side[x + *j_p] == '\0' && main[x + *i_p] != '\0') {
            side[x+*j_p] = '0';
        } else if(main[x] == '\0') {
            break;
        } 
    }

    setter_front(main, side, *i_p, *j_p);

    inverse(main);
    inverse(side);
        
    

    //make a for loop going from i = decimal place to 0 and doing basic addition 
}

void inverse(char *target) {
    char temp[N];
    int length_arr = strlen(target)-1;
    printf("length_arr:%d\n", length_arr);

    for (int i = 0; i <= length_arr;i++) {
        temp[length_arr-i] = target[i];
        //printf("%c | %d\n", target[length_arr-i], (length_arr-i));
    }
    temp[length_arr+1] = '\0';
    strcpy(target, temp);
}

void big_add(char *main, char *side, int i_p, int j_p) {
    int sum = 0;
    char temp[N] = {0};
    int len = strlen(main);
    int temp_nbr;

    for (int i = 0; i < len; i++) {
        printf("\n%c | %c\n", main[i], side[i]);
        //printf("sum: %d", sum);
        if (main[i] != '.' && side[i] != '.'){
            sum = (main[i]-'0') + (side[i]-'0');
            if (sum > 9) {
                temp_nbr =  sum/10;
                temp[i+1] += temp_nbr;
                temp[i] += sum%10 + '0';
                printf("\n\ncarry over %d | %d | %d\n\n", temp_nbr, sum, temp[i]);
            } else {
                temp[i] += sum+'0';
            }
        } else {
            temp[i+1] = temp[i]%10;
            temp[i] = '.';
        }
        printf("%c", temp[i]);
    }
    temp[len] = '\0';
    inverse(temp);
    printf("\n\ntemp: %s", temp);
}

void setter_front(char *main, char *side,int i_p, int j_p) {
    int diff = i_p - j_p; // if value positive, i_p bigger

    if (diff > 0) { //i_p + 1 and j_p + diff + 1 ->shifts right
        int len =strlen(side);
        printf("len : %d", diff);
        memmove(side+diff, side, len +1); //+1 is for \0

        for (int i =0; i < diff+1; i++) {
            side[i] = '0';
        }
    } else if (diff < 0) { //i_p + diff + 1 and j_p + 1 ->shifts left
        int len =strlen(main);
        diff = -diff;
        memmove(main+diff, main, len +1); //+1 is for \0

        for (int i =0; i < -diff+1; i++) {
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