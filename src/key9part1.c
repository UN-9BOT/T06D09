/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

void input (int *buffer, int *length, int *);
void output (int *buffer, int length);
int sum_numbers(int *buffer, int length);
void find_numbers(int* buffer, int length, int number, int* numbers);

int main() {
    int n, buffer[NMAX], numbers[NMAX], number;
    int flag = 0;

    input(buffer, &n, &flag);
    if (flag != 1) {
        printf("n/a");
    } else {
        number = sum_numbers(buffer, n);
        find_numbers(buffer, n, number, numbers);
        output(numbers, n);
    }
    return (0);
}

int sum_numbers(int *buffer, int length) {
	int sum = 0;
	
	for (int i = 1; i < length; i++)
	{
		if (i % 2 == 0)
		{
			sum += buffer[i];
		}
	}
	
	return sum;
}

void find_numbers(int* buffer, int length, int number, int* numbers) {
    for (int i = 0, k = 0; i < length; i++) {
        if (*(buffer + i) % number == 0) { *(numbers + k++) = *(buffer + i); }
    }
}

void input(int *data, int *n, int *flag) {
    int k;
    if (scanf("%d.%d", n, &k) != 1) {
        *flag = 1;
    } else {
        for (int i = 0; i < NMAX; i++) {
            if (scanf("%d.%d", (data + i), &k) != 1) {
                *flag = 1;
            }
        }
    }
}
