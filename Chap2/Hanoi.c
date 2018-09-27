/*
 * Hanoi.c
 *
 *  Created on: 2018. 9. 27.
 *      Author: ¿Ã»ø¡§
 */

#include <stdio.h>

void TowersOfHanoi(int n, char fromH, char toH, char auxH)
{
	if(n==1)
	{
		printf("Disk#%d from %c to %c\n", n, fromH, toH);
		return;
	}

	TowersOfHanoi(n-1, fromH, auxH, toH);

	printf("Disk#%d from %c to %c\n", n, fromH, toH);

	TowersOfHanoi(n-1, auxH, toH, fromH);
}

int main(void)
{
	int num;
	printf("This is a program for resolving Hanoi Top issue!!!\n");

	num = 3;
	TowersOfHanoi(num, 'A', 'C', 'B');

	return 0;
}

