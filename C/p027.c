/* Euler discovered the remarkable quadratic formula:
 *
 * n^2+n+41
 *
 * It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is
 * divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.
 *
 * The incredible formula n^2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79.
 * The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 *
 * n^2+an+b, where |a|<1000 and |b|≤1000
 *
 * where |n| is the modulus/absolute value of n
 * e.g. |11|=11 and |−4|=4
 *
 * Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int a, b, n, p, count, max = 0, save_a, save_b;
   int *primes;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Brute force approach, optimized by checking only values of b where b is prime.*/
   for(a = -999; a < 1000; a++)
   {
      for(b = 2; b <= 1000; b++)
      {
         /* For n=0, n^2+an+b=b, so b must be prime.*/
         if(is_prime(b))
         {
            n = 0;
            count = 0;

            while(1)
            {
               p = n * n + a * n + b;

               if(p > 1 && is_prime(p))
               {
                  count++;
                  n++;
               }
               else
               {
                  break;
               }
            }

            if(count > max)
            {
               max = count;
               save_a = a;
               save_b = b;
            }
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 27\n");
   printf("Answer: %d\n", save_a * save_b);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
