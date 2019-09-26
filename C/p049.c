/* The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime,
 * and, (ii) each of the 4-digit numbers are permutations of one another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit
 * increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this sequence?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 10000

int check_digits(int a, int b);

int *primes;

int main(int argc, char **argv)
{
   int i = 1489, j, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Starting from i=1489 (bigger than the first number in the sequence given in the problem),
    * check odd numbers. If they're prime, loop on even numbers j (odd+even=odd, odd+odd=even and
    * we need odd numbers because we're looking for primes) up to 4254 (1489+2*4256=10001 which has
    * 5 digits.*/
   while(i < N)
   {
      if(primes[i])
      {
         for(j = 2; j < 4255; j += 2)
         {
            /* If i, i+j and i+2*j are all primes and they have
             * all the same digits, the result has been found.*/
            if(i + 2 * j < N && primes[i+j] && primes[i+2*j] &&
                  check_digits(i, i+j) && check_digits(i, i+2*j))
            {
               found = 1;
               break;
            }
         }
      }
      if(found)
      {
         break;
      }
      i += 2;
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 49\n");
   printf("Answer: %d%d%d\n", i, i+j, i+2*j);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int check_digits(int a, int b)
{
   int i;
   int digits1[10] = {0}, digits2[10] = {0};

   while(a > 0)
   {
      digits1[a%10]++;
      a /= 10;
   }

   while(b > 0)
   {
      digits2[b%10]++;
      b /= 10;
   }

   for(i = 0; i < 10; i++)
   {
      if(digits1[i] != digits2[i])
      {
         return 0;
      }
   }

   return 1;
}
