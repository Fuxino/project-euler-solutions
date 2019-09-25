/* The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right,
 * and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int is_tr_prime(int n);

int main(int argc, char **argv)
{
   int i = 0, n = 1, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Check every number until 11 truncatable primes are found.*/
   while(i < 11)
   {
      if(is_tr_prime(n))
      {
         sum += n;
         i++;
      }
      n++;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 37\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_tr_prime(int n)
{
   int i, tmp;

   /* One-digit numbers and non-prime numbers are
    * not truncatable primes.*/
   if(n < 11 || !is_prime(n))
   {
      return 0;
   }

   /* Remove one digit at a time from the right and check
    * if the resulting number is prime. Return 0 if it isn't.*/
   tmp = n / 10;

   while(tmp > 0)
   {
      if(!is_prime(tmp))
      {
         return 0;
      }
      tmp /= 10;
   }

   /* Starting from the last digit, check if it's prime, then
    * add back one digit at a time on the left and check if it
    * is prime. Return 0 when it isn't.*/
   i = 10;
   tmp = n % i;

   while(tmp != n)
   {
      if(!is_prime(tmp))
      {
         return 0;
      }
      i *= 10;
      tmp = n % i;
   }

   /* If it gets here, the number is truncatable prime.*/
   return 1;
}
