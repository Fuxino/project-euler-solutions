#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int i, j, n, max = 0, max_n = 0;
   double elapsed;
   struct timespec start, end;
   mpz_t k, div;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(k);
   mpz_init(div);

   for(i = 2; i < 1000; i++)
   {
      j = i;

      while(j % 2 == 0 && j > 1)
         j /= 2;

      while(j % 5 == 0 && j > 1)
         j /= 5;

      mpz_set_ui(k, 9);

      if(j == 1)
         n = 0;
      else
      {
         n = 1;

         mpz_set_ui(div, j);

         while(!mpz_divisible_p(k, div))
         {
            n++;
            mpz_mul_ui(k, k, 10);
            mpz_add_ui(k, k, 9);
         }

         if(n > max)
         {
            max = n;
            max_n = i;
         }
      }
   }

   mpz_clears(k, div, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, Problem 26\n");
   printf("Answer: %d\n", max_n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
