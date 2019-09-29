/* Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers
 * less than or equal to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and
 * relatively prime to nine, φ(9)=6.
 * The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.
 *
 * Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.
 *
 * Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>
#include "projecteuler.h"

#define N 10000000

int is_permutation(int a, int b);

int main(int argc, char **argv)
{
   int i, a, b, p, n = -1;
   int *primes;
   double elapsed, min = DBL_MAX;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   primes = sieve(N);

   for(i = 2; i < N; i++)
   {
      /* When n is prime, phi(n)=(n-1), so to minimize n/phi(n) we should
       * use n prime. But n-1 can't be a permutation of n. The second best 
       * bet is to use semiprimes. For a semiprime n=p*q, phi(n)=(p-1)(q-1).
       * So we check if a number is semiprime, if yes calculate phi, finally
       * check if phi(n) is a permutation of n and update the minimum if it's
       * smaller.*/
      if(is_semiprime(i, &a, &b, primes))
      {
         p = phi_semiprime(i, a, b);

         if(is_permutation(p, i) && (double)i / p < min)
         {
            n = i;
            min = (double)i / p;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 70\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_permutation(int a, int b)
{
   int i;
   int digits1[10] = {0}, digits2[10] = {0};

   /* Get digits of a.*/
   while(a > 0)
   {
      digits1[a%10]++;
      a /= 10;
   }

   /* Get digits of b.*/
   while(b > 0)
   {
      digits2[b%10]++;
      b /= 10;
   }

   /* If they're not the same, return 0.*/
   for(i = 0; i < 10; i++)
   {
      if(digits1[i] != digits2[i])
      {
         return 0;
      }
   }

   return 1;
}
