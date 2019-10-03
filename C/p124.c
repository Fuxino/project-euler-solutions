/* The radical of n, rad(n), is the product of the distinct prime factors of n. For example, 504 = 23 × 32 × 7, so rad(504) = 2 × 3 × 7 = 42.
 *
 * If we calculate rad(n) for 1 ≤ n ≤ 10, then sort them on rad(n), and sorting on n if the radical values are equal, we get:
 *
 *    Unsorted             Sorted         
 *    n     rad(n)      n     rad(n)   k
 *    1     1           1     1        1
 *    2     2           2     2        2
 *    3     3           4     2        3
 *    4     2           8     2        4
 *    5     5           3     3        5
 *    6     6           9     3        6
 *    7     7           5     5        7
 *    8     2           6     6        8
 *    9     3           7     7        9
 *    10    10          10    10       10
 *
 * Let E(k) be the kth element in the sorted n column; for example, E(4) = 8 and E(6) = 9.
 *
 * If rad(n) is sorted for 1 ≤ n ≤ 100000, find E(10000).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 100000

typedef struct n_rad
{
   int n;
   int radn;
}n_radn;

int compare(void *a, void *b);

int main(int argc, char **argv)
{
   int i, *primes;
   n_radn **rads;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   if((rads = (n_radn **)malloc(N*sizeof(n_radn *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < N; i++)
   {
      if((rads[i] = (n_radn *)malloc(sizeof(n_radn))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   for(i = 0; i < N; i++)
   {
      rads[i]->n = i + 1;
      rads[i]->radn = radical(i+1, primes);
   }

   free(primes);

   quick_sort((void **)rads, 0, N-1, compare);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 124\n");
   printf("Answer: %d\n", rads[9999]->n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *a, void *b)
{
   n_radn *rad1, *rad2;

   rad1 = (n_radn *)a;
   rad2 = (n_radn *)b; 

   if(rad1->radn != rad2->radn)
   {
      return rad1->radn - rad2->radn;
   }
   else
   {
      return rad1->n - rad2->n;
   }
}
