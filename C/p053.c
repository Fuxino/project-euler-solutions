/* There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, (5 3) = 10.
 *
 * In general, (n r)=n!/(r!(n−r)!), where r≤n, n!=n×(n−1)×...×3×2×1, and 0!=1.
 *
 * It is not until n=23, that a value exceeds one-million: (23 10)=1144066.
 *
 * How many, not necessarily distinct, values of (n r) for 1≤n≤100, are greater than one-million?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

#define N 100
#define LIMIT 1000000

void binomial(mpz_t bin, unsigned long int n, unsigned long int k, mpz_t *factorials);

int main(int argc, char **argv)
{
   int i, j, count = 0;
   double elapsed;
   struct timespec start, end;
   mpz_t bin;
   mpz_t factorials[N+1];

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(bin);

   mpz_init_set_ui(factorials[0], 1);

   /* Straightforward brute force approach, using the GMP Library. First
    * calculate all factorials, then use them for the binomial coefficients.*/
   for(i = 1; i <= N; i++)
   {
      mpz_init(factorials[i]);
      mpz_fac_ui(factorials[i], i);
   }

   for(i = 23; i <= N; i++)
   {
      for(j = 1; j <= i; j++)
      {
         binomial(bin, i, j, factorials);

         if(mpz_cmp_ui(bin, LIMIT) > 0)
            count++;
      }
   }

   mpz_clear(bin);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 53\n");
   printf("Answer: %d\n", count);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void binomial(mpz_t bin, unsigned long n, unsigned long int k, mpz_t *factorials)
{
   mpz_t num, d1, d2; 

   mpz_inits(num, d1, d2, NULL);

   mpz_set(num, factorials[n]);
   mpz_set(d1, factorials[k]);
   mpz_set(d2, factorials[n-k]);

   mpz_mul(d1, d1, d2);
   mpz_tdiv_q(bin, num, d1);

   mpz_clears(num, d1, d2, NULL);
}
