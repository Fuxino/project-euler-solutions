/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *
 * a2 + b2 = c2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int a, b, c, tmpa, tmpb, tmpc, i, m, n, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Brute force approach: generate all the Pythagorean triplets using
    * Euclid's formula, until the one where a+b+c=1000 is found.*/
   for(m = 2; found == 0; m++)
   {
      for(n = 1; n < m && !found; n++)
      {
         if(gcd(m, n) == 1 && (m % 2 == 0 && n % 2 != 0 || m % 2 != 0 && n % 2 == 0))
         {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if(a + b + c == 1000)
            {
               found = 1;
               break;
            }

            i = 2;

            do
            {
               tmpa = a * i;
               tmpb = b * i;
               tmpc = c * i;

               if(tmpa + tmpb + tmpc == 1000)
               {
                  a = tmpa;
                  b = tmpb;
                  c = tmpc;
                  found = 1;
                  break;
               }
               
               i++;
            }while(tmpa + tmpb + tmpc < 1000);
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 9\n");
   printf("Answer: %d\n", a*b*c);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
