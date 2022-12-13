#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "part2.h"

void part2()
{
	FILE* fp;

	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		perror("Error opening file");
		return -1;
	}

	char* similarities = (char*)calloc(MAX * sizeof(char));
	int n = 0;

	char* buf1[MAXLINE];
	char* buf2[MAXLINE];
	char* buf3[MAXLINE];

	while (fgets(buf1, MAXLINE, fp) != NULL) {
		fgets(buf2, MAXLINE, fp);
		fgets(buf3, MAXLINE, fp);
		n = find_similarities_part2(similarities, buf1, buf2, buf3, n);
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
		printf("Some thing went wrong when calculating sum of priorities\n");
		return -1;
	}

	printf("part2 sum of priorities: %d\n", sum);

	free(similarities);
}

unsigned int find_similarities_part2(char* similarities, char* s1, char* s2, char* s3, int n)
{
	char possibleSimilarities[1000];
	unsigned int p = 0;

	/* get lenght of string */
	int s1len = strlen(s1) - 1;
	int s2len = strlen(s2) - 1;
	int s3len = strlen(s3) - 1;

	/* Loop trough 2 inputs and find similarities */
	for (int i = 0; i < s1len; ++i) {
		char x = s1[i];
		for (int j = 0; j < s2len; ++j) {
			char y = s2[j];
			if (x == y) {
				possibleSimilarities[p] = x;
				p++;
			}
		}
	}

	for (int i = 0; i < p; i++) {
		char x = possibleSimilarities[i];
		for (int j = 0; j < s3len; j++) {
			char y = s3[j];
			if (x == y) {
				similarities[n] = x;
				n++;
				goto end;
			}
		}
	}

end:

	return n;
}