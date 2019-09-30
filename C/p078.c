/* Let p(n) represent the number of different ways in which n coins can be separated into piles.
 * For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
 *
 *       OOOOO
 *      OOOO  O
 *      OOO  OO
 *     OOO  O  O
 *     OO  OO  O
 *    OO  O  O  O
 *   O  O  O  O  O
 *
 * Find the least value of n for which p(n) is divisible by one million.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int main(int argc, char **argv)
{
   int i = -1;
   long int partitions[N] = {0};
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Using the partition function to calculate the number of partitions,
    * giving the result modulo N.*/   
   while(partition_fn(++i, partitions, N) != 0);
	
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 78\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
