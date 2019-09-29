/* Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
 *
 * 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that there are 21 elements in this set.
 *
 * How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000001

int main(int argc, char **argv)
{
   int i;
   int *primes;
   long int count = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* For any denominator d, the number of reduced proper fractions is 
    * the number of fractions n/d where gcd(n, d)=1, which is the definition
    * of Euler's Totient Function phi. It's sufficient to calculate phi for each
    * denominator and sum the value.*/
   for(i = 2; i < N; i++)
   {
      count += phi(i, primes);
   }
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 72\n");
   printf("Answer: %ld\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
