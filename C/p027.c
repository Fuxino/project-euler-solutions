#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int a, b, n, p, count, max = 0, save_a, save_b;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(a = -999; a < 1000; a++)
   {
      for(b = 2; b <= 1000; b++)
      {
         n = 0;
         count = 0;

         while(1)
         {
            p = n * n + a * n + b;

            if(p > 1 && is_prime(p))
            {
               count++;
               n++;
            }
            else
            {
               break;
            }
         }

         if(count > max)
         {
            max = count;
            save_a = a;
            save_b = b;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 27\n");
   printf("Answer: %d\n", save_a * save_b);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
