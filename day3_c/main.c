#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "part1.h"
#include "part2.h"

/* 
	For some reason this program gives access error for compartment2, other times it does not, i dont know why
*/
/* Also program is slow, need ways to improve it */

int main()
{
	part1();
	part2();

	return 0;
}
