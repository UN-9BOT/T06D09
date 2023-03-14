#include <stdio.h>
#define NMAX 10

void input (int *, int *, int *);
void output (int *, int, int);
int sum_numbers(int *, int );
int find_numbers(int *, int, int, int *);

int main() {
    int nD, nN, data[NMAX], numbers[NMAX], res_number;
    int flag = 0;

    input(data, &nD, &flag);
    if (flag == 1) {
        printf("n/a");
    } else {
        res_number = sum_numbers(data, nD);
        nN = find_numbers(data, nD, nN, numbers);
        output(numbers, nN, number);
    }
    return (0);
}

int sum_numbers(int *buffer, int length) {
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (*(buffer + i) % 2 == 0)
		{
			sum += buffer[i];
		}
	}
	
	return sum;
}

int find_numbers(int* data, int length, int number, int* numbers) {
    int k = 0;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % number == 0) { 
            *(numbers + k) = *(buffer + i); 
            k++;
        }
    }
    return (k);
}

void input(int *data, int *n, int *flag) {
    int k;
    if (scanf("%d.%d", n, &k) != 1) {
        *flag = 1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d.%d", (data + i), &k) != 1) {
                *flag = 1;
            }
        }
    }
}

void output(int *buffer, int n, int number) {
    printf("%d\n", number);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", *(buffer + i));
    }
    printf("%d", *(buffer + n));
}
