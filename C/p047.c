/* The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2² × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 150000

int count_distinct_factors(int n);
   
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

   /* Starting from 647, count the distinct prime factors of n, n+1, n+2 and n+3.
    * If they all have 4, the solution is found.*/
   for(i = 647; !found && i < N - 3; i++)
   {
      if(!primes[i] && !primes[i+1] && !primes[i+2] && !primes[i+3])
      {
         if(count_distinct_factors(i) == 4 && count_distinct_factors(i+1) == 4 &&
               count_distinct_factors(i+2) == 4 && count_distinct_factors(i+3) == 4)
         {
            found = 1;
         }
      }
   }     

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 47\n");
   printf("Answer: %d\n", i-1);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_distinct_factors(int n)
{
   int i, count=0;

   /* Start checking if 2 is a prime factor of n. Then remove
    * all 2s factore.*/
   if(n % 2 == 0)
   {
      count++;

      do
      {
         n /= 2;
      }while(n % 2 == 0);
   }

   /* Check all odd numbers i, if they're prime and they're a factor
    * of n, count them and then divide n for by i until all factors i
    * are eliminated. Stop the loop when n=1, i.e. all factors have
    * been found.*/
   for(i = 3; n > 1; i += 2)
   {
      if(primes[i] && n % i == 0)
      {
         count++;

         do
         {
            n /= i;
         }while(n % i == 0);
      }
   }

   return count;
}
