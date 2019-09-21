#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, n, d, prod_n=1, prod_d=1, div;
   float f1, f2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 11; i < 100; i++)
   {
      for(j = 11; j < 100; j++)
      {
         if(i % 10 && j % 10 && i != j && i % 10 == j / 10)
         {
            n = i / 10;
            d = j % 10;

            f1 = (float)i / j;
            f2 = (float)n / d;

            if(f1 == f2)
            {
               prod_n *= i;
               prod_d *= j;
            }
         }
      }
   }

   div = gcd(prod_n, prod_d);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 33\n"); 
   printf("Answer: %d\n", prod_d/div);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
