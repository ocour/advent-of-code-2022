#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdbool.h> 

enum Result {
	LOSE = 0,
	TIE = 3,
	WIN = 6,
	ERROR,
};

enum Shape {
	ROCK = 1,
	PAPER = 2,
	SCISSORS = 3,
	SHAPEERROR,
};

int PART1();
int PART2();
enum Result calculateMove(char pick, char opponentPick);
enum Result rockPaperScissors(char yourpick, char opponentPick);
int pickToNum(char pick);
int outcomeToNum(char outcome);

int main() {
	
	int sumOfPART1 = PART1();
	printf("PART1 Total: %d\n", sumOfPART1);

	int sumOfPART2 = PART2();
	printf("PART2 Total: %d\n", sumOfPART2);
}

/* PART1 of day 2 */
int PART1() {
	const char* filename = "input_small.txt";
	unsigned int sum = 0;

	/* Open file and check for errors */
	FILE* filePtr = fopen(filename, "r");
	if (!filePtr) {
		perror("File opening failed");
		return -1;
	}

	char opponentPick = ' ';
	char yourPick = ' ';

	/* Loop till end of file */
	while ((opponentPick = fgetc(filePtr)) != EOF) {
		fgetc(filePtr);					// since next character is a space
		yourPick = fgetc(filePtr);
		fgetc(filePtr);					// since next character is a space

		/* Play rockpaperscissors and error check */
		int result = rockPaperScissors(yourPick, opponentPick);

		if (result == ERROR)
			return -1;

		/* convert yourpick to number and error check */
		int yourPickNum = pickToNum(yourPick);

		if (yourPick == -1)
			return -2;

		sum += yourPickNum + result;
	}

	/* Close opened file */
	fclose(filePtr);

	return sum;
}

int PART2() {
	const char* filename = "input_full.txt";
	unsigned int sum = 0;

	/* Open file and check for errors */
	FILE* filePtr = fopen(filename, "r");
	if (!filePtr) {
		perror("File opening failed");
		return -1;
	}

	char opponentPick = ' ';
	char outcome = ' ';

	/* Loop till end of file */
	while ((opponentPick = fgetc(filePtr)) != EOF) {
		fgetc(filePtr);					// since next character is a space
		outcome = fgetc(filePtr);
		fgetc(filePtr);					// since next character is a space

		/* calculate move needed for desired outcome and error check */
		int shapePlayed = calculateMove(outcome, opponentPick);
		if (shapePlayed == SHAPEERROR)
			return -3;

		/* convert outcome char to enum */
		int outcomeNum = outcomeToNum(outcome);
		if (outcomeNum == ERROR)
			return -4;

		sum += shapePlayed + outcomeNum;
	}

	/* Close opened file */
	fclose(filePtr);

	return sum;
}

/* calculate move needed for result of rockPaperScissors, based on opponent move and desired outcome */
enum Shape calculateMove(char outcome, char opponentPick) {
	/*
		X = LOSE
		Y = DRAW
		Z = WIN
	*/

	if (opponentPick == 'A' && outcome == 'X') {
		/* LOSE */
		return SCISSORS;
	}
	else if (opponentPick == 'A' && outcome == 'Y') {
		/* DRAW */
		return ROCK;
	}
	else if (opponentPick == 'A' && outcome == 'Z') {
		/* WIN */
		return PAPER;
	}
	else if (opponentPick == 'B' && outcome == 'X') {
		/* LOSE */
		return ROCK;
	}
	else if (opponentPick == 'B' && outcome == 'Y') {
		/* DRAW */
		return PAPER;
	}
	else if (opponentPick == 'B' && outcome == 'Z') {
		/* WIN */
		return SCISSORS;
	}
	else if (opponentPick == 'C' && outcome == 'X') {
		/* LOSE */
		return PAPER;
	}
	else if (opponentPick == 'C' && outcome == 'Y') {
		/* DRAW */
		return SCISSORS;
	}
	else if (opponentPick == 'C' && outcome == 'Z') {
		/* WIN */
		return ROCK;
	}

	/* incase something unexpected happenes */
	return SHAPEERROR;
}

/* Compares your and opponents picks, returns enum */
enum Result rockPaperScissors(char yourPick, char opponentPick) {
	/* ROCK AND ROCK */
	if (yourPick == 'X' && opponentPick == 'A') {
		return TIE;
	}
	/* ROCK AND PAPER */
	else if (yourPick == 'X' && opponentPick == 'B') {
		return LOSE;
	}
	/* ROCK AND SCISSORS */
	else if (yourPick == 'X' && opponentPick == 'C') {
		/* WIN */
		return WIN;
	}
	/* PAPER AND ROCK */
	else if (yourPick == 'Y' && opponentPick == 'A') {
		/* WIN */
		return WIN;
	}
	/* PAPER AND PAPER */
	else if (yourPick == 'Y' && opponentPick == 'B') {
		return TIE;
	}
	/* PAPER AND SCISSOR */
	else if (yourPick == 'Y' && opponentPick == 'C') {
		return LOSE;
	}
	/* SCISSORS AND ROCK */
	else if (yourPick == 'Z' && opponentPick == 'A') {
		return LOSE;
	}
	/* SCISSORS AND PAPER */
	else if (yourPick == 'Z' && opponentPick == 'B') {
		/* WIN */
		return WIN;
	}
	/* SCISSORS AND SCISSORS */
	else if (yourPick == 'Z' && opponentPick == 'C') {
		return TIE;
	}

	/* incase something unexpected happenes */
	return ERROR;
}

int pickToNum(char pick) {
	if (pick == 'X') {
		return 1;
	}
	else if (pick == 'Y') {
		return 2;
	}
	else if(pick == 'Z') {
		return 3;
	}
	else {
		return -1;
	}
}

int outcomeToNum(char outcome) {
	if (outcome == 'X') {
		return LOSE;
	}
	else if (outcome == 'Y') {
		return TIE;
	}
	else if (outcome == 'Z') {
		return WIN;
	}
	else {
		return ERROR;
	}
}