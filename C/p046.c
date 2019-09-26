/* It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2×1^2
 * 15 = 7 + 2×2^2
 * 21 = 3 + 2×3^2
 * 25 = 7 + 2×3^2
 * 27 = 19 + 2×2^2
 * 33 = 31 + 2×1^2
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 10000

int goldbach(int n);

int *primes;

int main(int argc, char **argv)
{
   int i, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* For every odd number, check if it's prime, if it is check
    * if it satisfies the Goldbach property. Continue until the 
    * first number that doesn't is found.*/
   for(i = 3; !found && i < N; i += 2)
   {
      if(!primes[i])
      {
         if(!goldbach(i))
         {
            found = 1;
         }
      }
   }

   free(primes);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 46\n");
   printf("Answer: %d\n", i-2);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int goldbach(int n)
{
   int i, j, tmp;

   /* Check every prime smaller than n.*/
   for(i = 3; i < n; i += 2)
   {
      if(primes[i])
      {
         j = 1;

         /* Check if summing twice a square to the prime number
          * gives n. Return 1 when succeeding.*/
         do
         {
            tmp = i + 2 * j * j;

            if(tmp == n)
            {
               return 1;
            }

            j++;
         }while(tmp < n);
      }
   }

   /* Return 0 if no solution is found.*/
   return 0;
}
