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

   primes = sieve(N);

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

   for(i = 2; i < n; i++)
   {
      if(primes[i])
      {
         j = 1;

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

   return 0;
}
