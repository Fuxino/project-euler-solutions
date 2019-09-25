/* The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
 * which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator
 * and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, n, d, prod_n = 1, prod_d = 1, div;
   float f1, f2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 11; i < 100; i++)
   {
      for(j = 11; j < 100; j++)
      {
         /* If the example is non-trivial, check if cancelling the digit that's equal
          * in numerator and denominator gives the same fraction.*/
         if(i % 10 && j % 10 && i != j && i % 10 == j / 10)
         {
            n = i / 10;
            d = j % 10;

            f1 = (float)i / j;
            f2 = (float)n / d;

            if(f1 == f2)
            {
               prod_n *= i;
               prod_d *= j;
            }
         }
      }
   }

   /* Find the greater common divisor of the fraction found.*/
   div = gcd(prod_n, prod_d);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 33\n"); 
   printf("Answer: %d\n", prod_d/div);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
