/* The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact,
 * there are exactly four numbers below fifty that can be expressed in such a way:
 *
 * 28 = 22 + 23 + 24
 * 33 = 32 + 23 + 24
 * 49 = 52 + 23 + 24
 * 47 = 22 + 33 + 24
 *
 * How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 50000000
#define SQRT_N 7071
#define RAD3_N 368
#define RAD4_N 84

int *primes;

int main(int argc, char **argv)
{
   int count = 0;
   int *numbers;
   long int i, j, k, n;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Generate primes up to the square root of the limit.*/
   if((primes = sieve(SQRT_N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   if((numbers = (int *)calloc(N, sizeof(int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   /* If i>sqrt(n), i*i will be >n, so n won't be a sum of
    * a square, cube and fourth power.*/
   for(i = 2; i <= SQRT_N; i++)
   {
      /* If i is not prime, try next number.*/
      if(primes[i])
      {
         /* If j>cubic_root(n), j*j*j will be >n.*/
         for(j = 2; j <= RAD3_N; j++)
         {
            if(primes[j])
            {
               /* If k>fourth_root(n), k*k*k*k will be >n.*/
               for(k = 2; k <= RAD4_N; k++)
               {
                  if(primes[k])
                  {
                     n = i * i + j * j * j + k * k * k * k;

                     /* Check if the number found is lower than the limit,
                      * and make sure it hasn't been found before.*/
                     if(n < N && numbers[n] == 0)
                     {
                        count++;
                        numbers[n] = 1;
                     }
                  }
               }
            }
         }
      }
   }

   free(primes);
   free(numbers);
   
   clock_gettime(CLOCK_MONOTONIC, &end);
   
   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;
   
   printf("Project Euler, Problem 87\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);
   
   return 0;
}
