/* The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime.
 * For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes
 * with this property.
 *
 * Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 10000

int cat(int i, int j);

int *primes;

int main(int argc, char **argv)
{
   int found = 0, p1, p2, p3, p4, p5, n;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Straightforward brute force approach.*/
   for(p1 = 3; p1 < N && !found; p1 += 2)
   {
      /* If p1 is not prime, go to the next number.*/
      if(!primes[p1])
      {
         continue;
      }

      for(p2 = p1 + 2; p2 < N && !found; p2 += 2)
      {
         /* If p2 is not prime, or at least one of the possible concatenations of
          * p1 and p2 is not prime, go to the next number.*/
         if(!primes[p2] || !is_prime(cat(p1, p2)) || !is_prime(cat(p2, p1)))
         {
            continue;
         }

         for(p3 = p2 + 2; p3 < N && !found; p3 += 2)
         {
            /* If p3 is not prime, or at least one of the possible concatenations of
            * p1, p2 and p3 is not prime, go to the next number.*/
            if(!primes[p3] || !is_prime(cat(p1, p3)) || !is_prime(cat(p3, p1)) ||
                  !is_prime(cat(p2, p3)) || !is_prime(cat(p3, p2)))
            {
               continue;
            }
 
            for(p4 = p3 + 2; p4 < N && !found; p4 += 2)
            {
               /* If p4 is not prime, or at least one of the possible concatenations of
               * p1, p2, p3 and p4 is not prime, go to the next number.*/
               if(!primes[p4] || !is_prime(cat(p1, p4)) || !is_prime(cat(p4, p1)) ||
                     !is_prime(cat(p2, p4)) || !is_prime(cat(p4, p2)) || 
                     !is_prime(cat(p3, p4)) || !is_prime(cat(p4, p3)))
               {
                  continue;
               }

               for(p5 = p4 + 2; p5 < N && !found; p5 += 2)
               {
                  /* If p5 is not prime, or at least one of the possible concatenations of
                  * p1, p2, p3, p4 and p5 is not prime, go to the next number.*/
                  if(!primes[p5] || !is_prime(cat(p1, p5)) || !is_prime(cat(p5, p1)) ||
                        !is_prime(cat(p2, p5)) || !is_prime(cat(p5, p2)) ||
                        !is_prime(cat(p3, p5)) || !is_prime(cat(p5, p3)) ||
                        !is_prime(cat(p4, p5)) || !is_prime(cat(p5, p4)))
                  {
                     continue;
                  }

                  /* If it gets here, the five values have been found.*/
                  n = p1 + p2 + p3 + p4 + p5;
                  found = 1;
               }
            }
         }
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);
   
   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, Problem 60\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int cat(int i, int j)
{
   char n[10];

   sprintf(n, "%d%d", i, j);

   return atoi(n);
}
