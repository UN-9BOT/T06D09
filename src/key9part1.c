#include <stdio.h>
#define NMAX 10

void input(int *, int *, int *);
void output(int, int, int *);
int sum_numbers(int *, int);
int find_numbers(int *, int, int, int *);

int main() {
    int nD, nN, data[NMAX], numbers[NMAX], res_number;
    int flag = 0;

    input(data, &nD, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        res_number = sum_numbers(data, nD);
        nN = find_numbers(data, nD, res_number, numbers);
        output(res_number, nN, numbers);
    }
    return (0);
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *data, int nD, int res_number, int *numbers) {
    int k = 0;
    for (int i = 0; i < nD; i++) {
        if (*(data + i) != 0 && res_number % *(data + i) == 0) {
            *(numbers + k) = *(data + i);
            k++;
        }
    }
    return (k);
}

void input(int *data, int *n, int *flag) {
    int k;
    if (scanf("%d.%d", n, &k) != 1 || *n > NMAX) {
        *flag = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d.%d", (data + i), &k) != 1) {
                *flag = 1;
            }
        }
    }
}

void output(int res_number, int nN, int *numbers) {
    printf("%d\n", res_number);
    for (int i = 0; i < nN - 1; i++) {
        printf("%d ", *(numbers + i));
    }
    printf("%d", *(numbers + nN - 1));
}
