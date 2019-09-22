#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int i;
   double elapsed;
   struct timespec start, end;
   mpz_t power, sum;
   char *res;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(sum, 0);
   mpz_init(power);

   for(i = 1; i <= 1000; i++)
   {
      mpz_ui_pow_ui(power, i, i);
      mpz_add(sum, sum, power);
   }

   res = mpz_get_str(NULL, 10, sum);
   
   mpz_clears(power, sum, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 48\n");
   printf("Answer: %s\n", res+strlen(res)-10);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
