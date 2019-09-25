/* It is possible to show that the square root of two can be expressed as an infinite continued fraction.
 *
 * √2=1+1/(2+1/(2+1/(2+…
 *
 * By expanding this for the first four iterations, we get:
 *
 * 1+1/2=3/2=1.5
 * 1+1/(2+1/2)=7/5=1.4
 * 1+1/(2+1/(2+1/2))=17/12=1.41666…
 * 1+1/(2+1/(2+1/(2+1/2)))=41/29=1.41379…
 *
 * The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits
 * in the numerator exceeds the number of digits in the denominator.
 *
 * In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int count_digits(mpz_t n);

int main(int argc, char **argv)
{
   int i, count = 0;
   mpz_t n, d, d2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(n, 1);
   mpz_init_set_ui(d, 1);
   mpz_init(d2);

   /* If n/d is the current term of the expansion, the next term can be calculated as
    * (n+2d)/(n+d). Using the GMP Library the problem becomes trivial.*/
   for(i = 1; i < 1000; i++)
   {
      mpz_mul_ui(d2, d, 2);
      mpz_add(d, n, d);
      mpz_add(n, n, d2);

      if(count_digits(n) > count_digits(d))
      {
         count++;
      }
   }

   mpz_clears(n, d, d2, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 57\n");
   printf("Answer: %d\n", count);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_digits(mpz_t n)
{
   int count = 0;
   mpz_t value;

   mpz_init_set(value, n);

   while(mpz_cmp_ui(value, 0))
   {
      mpz_tdiv_q_ui(value, value, 10);
      count++;
   }

   mpz_clear(value);

   return count;
}
