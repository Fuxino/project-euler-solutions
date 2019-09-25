/* A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros.
 * Despite their size, the sum of the digits in each number is only 1.
 *
 * Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int a, b, sum, max = 0;
   double elapsed;
   struct timespec start, end;
   mpz_t pow;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(pow);

   /* Straightforward brute force approach using the GMP Library.*/
   for(a = 1; a < 100; a++)
   {
      for(b = 1; b < 100; b++)
      {
         mpz_ui_pow_ui(pow, a, b);
         sum = 0;

         while(mpz_cmp_ui(pow, 0))
            sum += mpz_tdiv_q_ui(pow, pow, 10);

         if(sum > max)
            max = sum;
      }
   }

   mpz_clear(pow);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 56\n");
   printf("Answer: %d\n", max);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
