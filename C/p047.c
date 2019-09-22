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

   primes = sieve(N);

   for(i = 645; !found && i < N - 3; i++)
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

   if(n % 2 == 0)
   {
      count++;

      do
      {
         n /= 2;
      }while(n % 2 == 0);
   }

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
