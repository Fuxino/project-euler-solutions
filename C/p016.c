/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   double elapsed;
   struct timespec start, end;
   mpz_t p, sum, r;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Simply calculate 2^1000 with the GMP Library
    * and sum all the digits.*/
   mpz_init_set_ui(p, 2);
   mpz_init_set_ui(sum, 0);
   mpz_init(r);

   mpz_pow_ui(p, p, 1000);

   while(mpz_cmp_ui(p, 0))
   {
      /* To get each digit, simply get the reminder of the division by 10.*/
      mpz_tdiv_qr_ui(p, r, p, 10);
      mpz_add(sum, sum, r);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 16\n");
   gmp_printf("Answer: %Zd\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clears(p, sum, r, NULL);

   return 0;
}
