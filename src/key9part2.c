#include <stdio.h>

#define LEN 100

// void sum(int *, int, int *, int, int);
// void sub(int *, int, int *, int, int);
void input(int *, int *, int *, int *, int *);
void output(int *, int);

int main(void) {
    int n1, n2, data1[LEN], data2[LEN], flag;
    flag = 0;
    n1 = n2 = 0;
    input(&n1, &n2, data1, data2, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        output(data1, n1);
        output(data2, n2);
    }
    return (0);
}


void input(int *n1, int *n2, int *data1, int *data2, int *flag) {
    int sym;
    
    while ((sym = getchar()) != '\n') {
        if (*n1 % 2 != 0) {
            if (sym != ' ' || sym != '\n') {
                *flag = 1;
            }
        } else if (*n1 % 2 == 0) {
            if (sym < 48 || sym > 57) {
                *flag = 1;
            }
        } else {
            *(data1 + *n1) = sym - '0';
            (*n1)++;
            //printf("\n\n\nn2 = %i\n\n\n", *n1);
        }
    }
    while ((sym = getchar()) != '\n') {
        if (*n2 % 2 == 0) {
            if (sym != ' ' || sym != '\n') {
                *flag = 1;
            }
        } else if (*n2 % 2 == 0) {
            if (sym < 48 || sym > 57) {
                *flag = 1;
            }
        } else {
            *(data2 + *n2) = sym - '0';
            (*n2)++;
            //printf("\n\n\nn2 = %i\n\n\n", *n1);
        }
    }
}

void output(int *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", *(data + i));
    }
    printf("%d", *(data + n - 1));
}
