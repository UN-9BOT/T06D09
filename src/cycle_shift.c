#include <stdio.h>
#define NMAX 10
void input(int *, int *, int *, int *);
void output(int *, int);
void shift(int *, int, int *, int);

int main(void) {
    int n, data[NMAX], nData[NMAX], flag, vShift;

    flag = 0;
    input(data, &n, &flag, &vShift);
    if (flag == 1) {
        printf("n/a");
    } else {
        shift(data, n, nData, vShift);
        output(nData, n);
    }

    return (0);
}

void shift(int *data, int n, int *nData, int sh) {
    if (sh > 0) {
        for (int i = 0, k = n - sh; i < n; i++, k++) {
            if (k >= n) {
                k = 0;
            }
            *(nData + k) = *(data + i);
        }
    } else {
        sh = -sh;
        for (int i = 0, k = sh; i < n; i++, k++) {
            if (k >= n) {
                k -= n;
            }
            *(nData + k) = *(data + i);
        }
    }
}

void input(int *data, int *n, int *flag, int *vShift) {
    int k;
    if (scanf("%d.%d", n, &k) != 1 || *n > NMAX) {
        *flag = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d.%d", (data + i), &k) != 1) {
                *flag = 1;
            }
        }
        if (scanf("%d.%d", vShift, &k) != 1) {
            *flag = 1;
        }
        *vShift %= *n;
    }
}

void output(int *nData, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", *(nData + i));
    }
    printf("%d", *(nData + n - 1));
}
