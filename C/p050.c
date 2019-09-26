/* The prime 41, can be written as the sum of six consecutive primes:
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int main(int argc, char **argv)
{
   int i, j, max = 0, max_p = 0, sum, count;
   int *primes;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Starting from a prime i, add consecutive primes until the 
    * sum exceeds the limit, every time the sum is also a prime
    * save the value and the count if the count is larger than the
    * current maximum. Repeat for all primes below N.
    * A separate loop is used for i=2, so later only odd numbers are 
    * checked for primality.*/
   i = 2;
   count = 1;
   sum = i;

   for(j = i + 1; j < N && sum < N; j++)
   {
      if(primes[j])
      {
         sum += j;
         count++;

         if(sum < N && primes[sum] && count > max)
         {
            max = count;
            max_p = sum;
         }
      }
   }

   for(i = 3; i < N; i += 2)
   {
      if(primes[i])
      {
         count = 1;
         sum = i;

         for(j = i + 2; j < N && sum < N; j += 2)
         {
            if(primes[j])
            {
               sum += j;
               count++;

               if(sum < N && primes[sum] && count > max)
               {
                  max = count;
                  max_p = sum;
               }
            }
         }
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 50\n");
   printf("Answer: %d\n", max_p);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
