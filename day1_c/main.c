#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 30
#define MAX_ARRAY_SIZE 1000

void readInputs(int calories[], char fileName[]);

/* advent of code 2022 day 1  */

int main()
{
    int calories[MAX_ARRAY_SIZE] = { 0 };
    unsigned int largest1 = 0;
    unsigned int largest2 = 0;
    unsigned int largest3 = 0;
    unsigned int sumOfAll = 0;

    readInputs(calories, "input.txt");

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        int sum = calories[i];
        if (sum > largest1) {
            largest1 = sum;
        }

        if (sum == 0) {
            break;
        }
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        int sum = calories[i];
        if (sum > largest2 && sum != largest1) {
            largest2 = sum;
        }

        if (sum == 0) {
            break;
        }
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        int sum = calories[i];
        if (sum > largest3 && sum != largest1 && sum != largest2) {
            largest3 = sum;
        }

        if (sum == 0) {
            break;
        }
    }

    printf("1: %d, 2: %d, 3: %d", largest1, largest2, largest3);

    sumOfAll = largest1 + largest2 + largest3;

    printf("total of top3: %d", sumOfAll);

    return 0;
}

void readInputs(int calories[], const char fileName[])
{
    int cal = 0;
    int index = 0;

    FILE* ptr;
    errno_t err;
    char str[MAXLINE];

    ptr = fopen(fileName, "r");

    if (NULL == ptr) {
        printf("file can't be opened\n");
    }

    printf("content of this file are\n");

    while (fgets(str, MAXLINE, ptr) != NULL) {
        int num = atoi(str);
        /* printf("%d\n", num); */

        if (num != 0) {
            cal += num;
        }
        else {
            calories[index] = cal;
            cal = 0;
            index++;
        }
    }
    /* Its amnoying but i dont know any other way to add the last one*/
    calories[index] = cal;

    fclose(ptr);
}