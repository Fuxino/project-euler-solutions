#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 10000

int check_digits(int a, int b);

int *primes;

int main(int argc, char **argv)
{
   int i, j, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   for(i = 1489; i < N && !found; i++)
   {
      if(primes[i])
      {
         for(j = 1; j < 4255; j++)
         {
            if(i + 2 * j < N && primes[i+j] && primes[i+2*j] &&
                  check_digits(i, i+j) && check_digits(i, i+2*j))
            {
               found = 1;
               break;
            }
         }
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 49\n");
   printf("Answer: %d%d%d\n", i-1, i-1+j, i-1+2*j);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int check_digits(int a, int b)
{
   int i;
   int digits1[10] = {0}, digits2[10] = {0};

   while(a > 0)
   {
      digits1[a%10]++;
      a /= 10;
   }

   while(b > 0)
   {
      digits2[b%10]++;
      b /= 10;
   }

   for(i = 0; i < 10; i++)
   {
      if(digits1[i] != digits2[i])
      {
         return 0;
      }
   }

   return 1;
}
