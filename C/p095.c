/* The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors
 * of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.
 *
 * Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220,
 * forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.
 *
 * Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:
 *
 * 12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)
 *
 * Since this chain returns to its starting point, it is called an amicable chain.
 *
 * Find the smallest member of the longest amicable chain with no element exceeding one million.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int sum_proper_divisors(int i);
int sociable_chain(int i, int start, int *min, int l);

int chains[N] = {0};
/* Vector to save the current chain values. I started with a longer vector,
 * but no chain is longer than 100 elements, so this is sufficient.*/
int c[100];
int divisors[N] = {0};
int *primes;

int main(int argc, char **argv)
{
   /* l_max starts from 3 because we're interested in chains of at least 3 elements.*/
   int i, min = 0, min_tmp, length, l_max = 2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N+1)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   for(i = 4; i <= N; i++)
   {
      /* Calculate the divisors of i, or retrieve the value if previously calculated.
       * If i is equal to the sum of its proper divisors, the length of the chain is 1
       * (i.e. i is a perfect number.*/
      if(divisors[i] == i || (divisors[i] = sum_proper_divisors(i)) == i)
      {
         length = 1;
         chains[i] = length;
      }
      else if(!primes[i])
      {
         min_tmp = i;
         length = sociable_chain(i, i, &min_tmp, 0);
      }
      /* If i is prime, 1 is its only proper divisor, so no amicable chain is possible.*/
      else
      {
         length = -1;
         chains[i] = length;
      }

      if(length > l_max)
      {
         l_max = length;
         min = min_tmp;
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 95\n");
   printf("Answer: %d\n", min);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int sum_proper_divisors(int n)
{
   int i, limit, sum = 1;

   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         sum += i;
         sum += n / i;
      }
   }

   if(n == limit * limit)
   {
      sum -= limit;
   }

   return sum;
}

int sociable_chain(int i, int start, int *min, int l)
{
   int n;

   /* If we already calculated that the current value can't form a chain,
    * or has a chain starting from a different number, it can't form a
    * chain starting with the current number, so just return -1.*/
   if(chains[i] != 0)
   {
      chains[start] = -1;
      return -1;
   }

   /* If we reached a prime number, the chain will never return to the starting number.*/
   if(primes[i])
   {
      chains[start] = -1;
      return -1;
   }

   /* Calculate the divisors of i, or retrieve the value if previously calculated.*/
   if(divisors[i] != 0)
   {
      chains[start] = -1;
      n = divisors[i];
   }
   else
   {
      n = sum_proper_divisors(i);
      divisors[i] = n;
   }

   /* If the next number in the chain is equal to the starting one, the chain is finished.*/
   if(n == start)
   {
      chains[start] = l + 1;
      return l + 1;
   }

   /* Save n, i.e. the next value in the chain, and check if it's equal
    * to another value of the chain different from start. If it is, the
    * chain is stuck in a loop that will not return to the starting number.*/
   c[l] = n;

   for(i = 0; i < l; i++)
   {
      if(n == c[i])
      {
         chains[start] = -1;
         return -1;
      }
   }

   /* We are looking for chain where no value is greater than 1000000.*/
   if(n > N)
   {
      chains[start] = -1;
      return -1;
   }

   /* If the next value is smaller than the minimum value of the chain,
    * update the minimum.*/
   if(n < *min)
   {
      *min = n;
   }

   return sociable_chain(n, start, min, l+1);
}
