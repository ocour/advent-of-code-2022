#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100
#define MAXLINE 1000

unsigned int findSimilarities(char* similarities, char* s, int n);
int calculateSumOfPriorities(char* arr, int size);
bool checkCharValidity(char* array, int size, char c);

/* 
	For some reason this program gives access error for compartment2, other times it does not, i dont know why, 
	might have fixed with (i + half), rather than just i + half;
*/
/* Also program is slow, need ways to improve it */

int main()
{
	FILE* fp;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return -1;
	}

	char* similarities = (char*)calloc(MAX * sizeof(char));
	int n = 0;

	char* buf[MAXLINE];

	while (fgets(buf, MAXLINE, fp) != NULL) {
		n = findSimilarities(similarities, buf, n);
	}
	fclose(fp);

	/* if no similarities were found */
	if (n == 0) {
		printf("No similarities");
		return 0;
	}

	/* Realloc array to only take needed space */
	similarities = (char*)realloc(similarities, n * sizeof(char));

	int sum = calculateSumOfPriorities(similarities, n);
	if (sum < 0) {
		printf("Some thing went wrong when calculating sum of priorities");
		return -1;
	}

	printf("sum of priorities: %d", sum);

	/* Free allocated memory */
	free(similarities);
	return 0;
}

int calculateSumOfPriorities(char* arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++) {
		char c = arr[i];
		if (islower(c)) {
			/*
				uses ascii table, lowercase letter a is 97, so we - 96 from character
				examples, a = 97 = 97 - 96 = 1, p = 112 = 112 - 96 = 16
				Lowercase item types a through z have priorities 1 through 26.
			*/
			sum += c - 96;
		}
		else if (isupper(c)) {
			/*
			* again uses ascii table
				Uppercase item types A through Z have priorities 27 through 52.
			*/
			sum += (c - 65) + 27;
		}
		else {
			return -1;
		}
	}

	return sum;
}

unsigned int findSimilarities(char* similarities, char* s, int n)
{
	char* inputString = s;

	/* get lenght of string */
	int slen = strlen(inputString) - 1;
	int half = slen / 2;

	char* compartment1 = (char*)malloc(half * sizeof(char));
	for (int i = 0; i < half; ++i) {
		compartment1[i] = inputString[i];
	}

	char* compartment2 = (char*)malloc(half * sizeof(char));
	for (int i = 0; i < half; ++i) {
		compartment2[i] = inputString[(i + half)];
	}

	//printf("%s : %s\n", compartment1, compartment2);

	/* Loop trough compartments and find similarities */
	for (int i = 0; i < half; ++i) {
		char x = compartment1[i];
		for (int j = 0; j < half; ++j) {
			char y = compartment2[j];
			if (x == y) {
				similarities[n] = x;
				n++;
				goto end;
			}
		}
	}

end:

	/* Free allocated memory */
	free(compartment1);
	free(compartment2);

	return n;
}

/* Checks if char to be added is a valid one, is not already included and is not a space */
bool checkCharValidity(char* array, int size, char c)
{
	// If char is a space return invalid
	if (c == ' ')
		return true;

	bool invalid = false;

	for (int i = 0; i < size; i++) {
		if (array[i] == c) {
			invalid = true;
		}
	}

	return invalid;
}
