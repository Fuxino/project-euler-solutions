/* The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 *
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int is_circular_prime(int n);

int *primes;

int main(int argc, char **argv)
{
   int i, count = 13;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Calculate all primes below one million, then check if they're circular.*/
   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Starting from 101 because we already know that there are 13 circular primes below 100.*/
   for(i = 101; i < 1000000; i += 2)
   {
      if(is_circular_prime(i))
      {
         count++;
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 35\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_circular_prime(int n)
{
   int i, tmp, count;

   /* If n is not prime, it's obviously not a circular prime.*/
   if(primes[n] == 0)
   {
      return 0;
   }

   /* The primes below 10 are circular primes.*/
   if(primes[n] == 1 && n < 10)
   {
      return 1;
   }

   tmp = n;
   count = 0;

   while(tmp > 0)
   {
      /* If the number has one or more even digits, it can't be a circular prime.
       * because at least one of the rotations will be even.*/
      if(tmp % 2 == 0)
      {
         return 0;
      }
      /* Count the number of digits.*/
      count++;
      tmp /= 10;
   }

   for(i = 1; i < count; i++)
   {
      /* Generate rotations and check if it's primes.*/
      n = n % (int)pow(10, count-1) * 10 + n / (int)pow(10, count-1);
      if(primes[n] == 0)
      {
         return 0;
      }
   }

   return 1;
}
