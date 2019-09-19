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

   mpz_inits(fact, r, sum, NULL);

   mpz_fac_ui(fact, 100);

   mpz_set_ui(sum, 0);

   while(mpz_cmp_ui(fact, 0))
   {
      mpz_tdiv_qr_ui(fact, r, fact, 10);
      mpz_add(sum, sum, r);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, Problem 20\n");
   gmp_printf("Answer: %Zd\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clears(fact, r, sum, NULL);

   return 0;
}
