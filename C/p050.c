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

   for(i = 2; i < N; i++)
   {
      if(primes[i])
      {
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
