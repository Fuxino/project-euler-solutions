/* It is possible to write ten as the sum of primes in exactly five different ways:
 *
 * 7 + 3
 * 5 + 5
 * 5 + 3 + 2
 * 3 + 3 + 2 + 2
 * 2 + 2 + 2 + 2 + 2
 *
 * What is the first value which can be written as the sum of primes in over five thousand different ways?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int count(int value, int n, int i, int target);
   
int primes[100];

int main(int argc, char **argv)
{
	int i, j, n;
	double elapsed;
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

   /* Generate a list of the first 100 primes.*/
	for(i = 0, j = 0; j < 100; i++)
	{
		if(is_prime(i))
      {
			primes[j++] = i;
      }
	}

	i = 1;

   /* Use a function to count the number of prime partitions for 
    * each number >= 2 until the one that can be written in over
    * 5000 ways is found.*/
	while((n = count(0, 0, 0, ++i)) <= 5000);

	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 77\n");
	printf("Answer: %d\n", i);

	printf("Elapsed time: %.9lf seconds\n", elapsed);

	return 0;
}

/* Function using a simple recursive brute force approach
 * to find all the partitions.*/
int count(int value, int n, int i, int target)
{
	int j;

	for(j = i; j < 100; j++)
	{
		value += primes[j];

		if(value == target)
      {
			return n + 1;
      }
		else if(value > target)
      {
			return n;
      }
		else
		{
			n = count(value, n, j, target);
			value -= primes[j];
		}
	}

	return n;
}
