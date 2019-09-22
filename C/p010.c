/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

#define N 2000000

int main(int argc, char **argv)
{
   int i; 
   int *primes;
   long int sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Use the function in projecteuler.c implementing the 
    * Sieve of Eratosthenes algorithm to generate primes.*/
   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Sum all the primes.*/
   for(i = 0; i < N; i++)
   {
      if(primes[i])
      {
         sum += i;
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 10\n");
   printf("Answer: %ld\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
