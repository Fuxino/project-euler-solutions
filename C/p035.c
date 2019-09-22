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

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

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

   if(primes[n] == 0)
   {
      return 0;
   }

   tmp = n;
   count = 0;

   while(tmp > 0)
   {
      if(tmp % 2 == 0)
      {
         return 0;
      }
      count++;
      tmp /= 10;
   }

   for(i = 1; i < count; i++)
   {
      n = n % (int)pow(10, count-1) * 10 + n / (int)pow(10, count-1);
      if(primes[n] == 0)
      {
         return 0;
      }
   }

   return 1;
}
