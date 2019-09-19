#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   double elapsed;
   struct timespec start, end;
   mpz_t count, tmp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_inits(count, tmp, NULL);
   mpz_fac_ui(count, 40);
   mpz_fac_ui(tmp, 20);
   mpz_mul(tmp, tmp, tmp);
   mpz_tdiv_q(count, count, tmp);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 15\n");
   gmp_printf("Answer: %Zd\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clears(count, tmp, NULL);

   return 0;
}
