/* The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
 *
 * How many n-digit positive integers exist which are also an nth power?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gmp.h>

int count_digits(mpz_t n);

int main(int argc, char **argv)
{
   int i, j, count = 0, finished = 0;
   double elapsed;
   struct timespec start, end;
   mpz_t p;

   mpz_init(p);

   clock_gettime(CLOCK_MONOTONIC, &start);

   i = 1;

   while(!finished) 
   {
      /* When j=10, j^i will have i+1 digits (e.g if i=3, 10^3=1000).*/
      for(j = 1; j < 10; j++)
      {
         mpz_ui_pow_ui(p, j, i);

         if(count_digits(p) == i)
         {
            count++;
         }
      }

      /* When 9^i has less than i digits, all the numbers have been found.*/
      if(count_digits(p) < i)
      {
         finished = 1;
      }

      i++;
   }

   mpz_clear(p);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 63\n");
   printf("Answer: %d\n", count);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_digits(mpz_t n)
{
   int count = 0;
   mpz_t tmp;

   if(mpz_cmp_ui(n, 0) == 0)
   {
      return 1;
   }

   mpz_init_set(tmp, n);

   while(mpz_cmp_ui(tmp, 0))
   {
      mpz_tdiv_q_ui(tmp, tmp, 10);
      count++;
   }

   return count;
}
