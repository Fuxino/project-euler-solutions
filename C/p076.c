/* It is possible to write five as a sum in exactly six different ways:
 *
 * 4 + 1
 * 3 + 2
 * 3 + 1 + 1
 * 2 + 2 + 1
 * 2 + 1 + 1 + 1
 * 1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count(int value, int n, int i);

int integers[99];

int main(int argc, char **argv)
{
	int i, n;
	double elapsed;
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

	for(i = 0; i < 99; i++)
		integers[i] = i + 1;

	n = count(0, 0, 0);

	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 76\n");
	printf("Answer: %d\n", n);

	printf("Elapsed time: %.9lf seconds\n", elapsed);

	return 0;
}

int count(int value, int n, int i)
{
	int j;

	for(j = i; j < 99; j++)
	{
		value += integers[j];

		if(value == 100)
      {
			return n + 1;
      }
		else if(value > 100)
      {
			return n;
      }
		else
		{
			n = count(value, n, j);
			value -= integers[j];
		}
	}

	return n;
}
