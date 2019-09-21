#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int i;
   unsigned long int digit;
   double elapsed;
   struct timespec start, end;
   mpz_t a, b, q, sum_f, sum, factorials[10];

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(a, 10);
   mpz_init_set_ui(sum, 0);
   mpz_inits(b, q, sum_f, sum, NULL);

   for(i = 0; i < 10; i++)
   {
      mpz_init_set_ui(factorials[i], 1);
   }

   for(i = 2; i < 10; i++)
   {
      mpz_fac_ui(factorials[i], i);
   }

   while(mpz_cmp_ui(a, 50000) < 0)
   {
      mpz_set(b, a);
      mpz_set_ui(sum_f, 0);

      while(mpz_cmp_ui(b, 0))
      {
         digit = mpz_fdiv_qr_ui(b, q, b, 10);
         mpz_add(sum_f, sum_f, factorials[digit]);
      }

      if(!mpz_cmp(a, sum_f))
      {
         mpz_add(sum, sum, a);
      }

      mpz_add_ui(a, a, 1);
   }

   mpz_clears(a, b, q, sum_f, NULL);

   for(i = 0; i < 10; i++)
   {
      mpz_clear(factorials[i]);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 34\n");
   gmp_printf("Answer: %Zd\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clear(sum);

   return 0;
}
