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

#define N 150000

int *count_factors(int n);

int main(int argc, char **argv)
{
   int i, count, res;
   int *factors;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((factors = count_factors(N)) == NULL)
   {
      fprintf(stderr, "Error! Count_factors function returned NULL\n");
      return 1;
   }

   count = 0;

   for(i = 0; i < N; i++)
   {
      if(factors[i] == 4)
      {
         count++;
      }
      else
      {
         count = 0;
      }

      if(count == 4)
      {
         res = i - 3;
         break;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 47\n");
   printf("Answer: %d\n", res);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Function using a modified sieve of Eratosthenes to count
 * the distinct prime factors of each number.*/
int *count_factors(int n)
{
   int i = 2, j;
   int *factors;

   if((factors = (int *)calloc(n, sizeof(int))) == NULL)
   {
      return NULL;
   }

   while(i < n / 2)
   {
      if(factors[i] == 0)
      {
         for(j = i; j < n; j += i)
         {
            factors[j]++;
         }
      }
      i++;
   }

   return factors;
}
