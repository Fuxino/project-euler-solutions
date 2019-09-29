/* Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
 *
 * If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
 *
 * 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
 *
 * It can be seen that 2/5 is the fraction immediately to the left of 3/7.
 *
 * By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size, find the numerator
 * of the fraction immediately to the left of 3/7.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int main(int argc, char **argv)
{
   int i, j, n, d, max_n;
   double elapsed, max = 0.0;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* For each denominator q, we need to find the biggest numerator p for which
    * p/q<a/b, where a/b is 3/7 for this problem. So:
    * pb<aq
    * pb<=aq-1
    * p<=(aq-1)/b
    * So we can set p=(3*q-1)/7 (using integer division).*/
   for(i = 2; i <= N; i++)
   {
      j = (3 * i - 1) / 7;

      if((double)j / i > max)
      {
         n = j;
         d = i;
         max = (double)n / d;

         /* Reduce the fraction if it's not already reduced.*/
         if(gcd(i, j) > 1)
         {
            n /= gcd(i, j);
            d /= gcd(i, j);
         }

         max_n = n;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 71\n");
   printf("Answer: %d\n", max_n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
