/* n! means n × (n − 1) × ... × 3 × 2 × 1
 *
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   double elapsed;
   struct timespec start, end;
   mpz_t fact, r, sum;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Calculate the factorial using the GMP Library and sum the digits.*/
   mpz_inits(fact, r, sum, NULL);

   mpz_fac_ui(fact, 100);

   mpz_set_ui(sum, 0);

   while(mpz_cmp_ui(fact, 0))
   {
      mpz_tdiv_qr_ui(fact, r, fact, 10);
      mpz_add(sum, sum, r);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 20\n");
   gmp_printf("Answer: %Zd\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clears(fact, r, sum, NULL);

   return 0;
}
