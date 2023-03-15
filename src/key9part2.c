#include <stdio.h>

#define LEN 100

void sum(int *, int, int *, int, int *, int *);
void sub(int *, int, int *, int, int *);
void input(int *, int *, int *, int *, int *);
void output(int *, int);

int main(void) {
    int n1, n2, n3, data1[LEN], data2[LEN], data3[LEN], flag;
    flag = 0;
    n1 = n2 = n3 = 0;
    input(&n1, data1, &n2, data2, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        output(data1, n1);
        output(data2, n2);
        sum(data1, n1, data2, n2, data3, &n3);
        output(data3, n3)
    }
    return (0);
}

void input(int *n1, int *data1, int *n2, int *data2, int *flag) {
    int sym, odd;

    odd = 0;
    while ((sym = getchar()) != '\n') {
        if (odd % 2 != 0) {
            if (sym != ' ') {
                *flag = 1;
            }
        } else if (odd % 2 == 0) {
            if (sym < 48 || sym > 57) {
                *flag = 1;
            }
        }
        *(data1 + *n1) = sym - '0';
        odd++;
        if (*flag == 0 && sym != '\n' && sym != ' ') {
            (*n1)++;
        }
    }
    odd = 0;
    while ((sym = getchar()) != '\n') {
        if (odd % 2 != 0) {
            if (sym != ' ') {
                *flag = 1;
            }
        } else if (odd % 2 == 0) {
            if (sym < 48 || sym > 57) {
                *flag = 1;
            }
        }
        *(data2 + *n2) = sym - '0';
        odd++;
        if (*flag == 0 && sym != '\n' && sym != ' ') {
            (*n2)++;
        }
    }
}

void output(int *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(data + i));
    }
}

void sum(int *data1, int n1, int *data2, int n2, int *data3, int *n3) {
    int buf = 0;
    for (int i = n1; i > 0; i--) {
        if (*(data1 + i) + *(data2 + i) + buf > 9) {
            *(data3 + i) = (*(data1 + i) + *(data2 + i) + buf) % 9;
            buf++;
            (*n3)++;
        }
    }
}
