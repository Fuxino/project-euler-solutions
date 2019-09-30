/* It is well known that if the square root of a natural number is not an integer, then it is irrational.
 * The decimal expansion of such square roots is infinite without any repeating pattern at all.
 *
 * The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.
 *
 * For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits
 * for all the irrational square roots*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gmp.h>

int is_square(int n);

int main(int argc, char **argv)
{
   int i, j, sum = 0;
   char sqrt_digits[104];
   double elapsed;
   struct timespec start, end;
   mpf_t sqrt;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Set the precision to 333 bits (should be enough for 100 decimal digits.*/
   mpf_set_default_prec(333);
   mpf_init(sqrt);

   for(i = 2; i < 100; i++)
   {
      if(is_square(i))
      {
         continue;
      }

      /* Calculate the square root of the current number with the given precision
       * and sum the digits to the total.*/
      mpf_sqrt_ui(sqrt, i);
      gmp_sprintf(sqrt_digits, "%.101Ff\n", sqrt);
      sum += (sqrt_digits[0] - '0');

      for(j = 2; j < 101; j++)
      {
         sum += (sqrt_digits[j] - '0');
      }
   }

   mpf_clear(sqrt);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 80\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_square(int n)
{
   int m;
   double p;

   p = sqrt(n);
   m = p;

   if(p == m)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
