#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
#define MAXLINE 1000

unsigned int findSimilarities(char* similarities, char* s, int n);
int calculateSumOfPriorities(char* arr, int size);
void part1();