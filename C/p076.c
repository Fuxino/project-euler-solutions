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
#include "projecteuler.h"

int main(int argc, char **argv)
{
	int i, n;
   long int *partitions;
	double elapsed;
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);

   if((partitions = (long int *)calloc(100, sizeof(long int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   /* The number of ways a number can be written as a sum is given by the partition function
    * (-1 because the partition function includes also the number itself).
    * The function is implemented in projecteuler.c*/
	n = partition_fn(100, partitions) - 1;

   free(partitions);

	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 76\n");
	printf("Answer: %d\n", n);

	printf("Elapsed time: %.9lf seconds\n", elapsed);

	return 0;
}
