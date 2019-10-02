/* The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1;
 * it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.
 *
 * However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.
 *
 * Find the last ten digits of this prime number.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int b = 2, e = 7830457, e_first;
   long int  m = 10000000000, c, result;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Using modular exponentiation algorithm to calculate 2^7830457. The algorithm is:
    * Set c=1, e'=0
    * Increment e' by 1
    * Set c=b*c%m, where b is the base (2) and m is the modulo (10000000000 since
    * we want the last 10 digits.
    * If e'<e (where e is the exponent), repeat step 3, otherwise c contains the result.*/
   c = 1;
   e_first = 0;

   while(e_first < e)
   {
      e_first++;
      c = (b * c) % m;
   }

   result = (c * 28433 + 1) % m;

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 97\n");
   printf("Answer: %ld\n", result);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
