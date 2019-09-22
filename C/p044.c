#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int n, m, pn, pm, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   n = 2;

   while(!found)
   {
      pn = n * (3 * n - 1) / 2;

      for(m = 1; m < n; m++)
      {
         pm = m * (3 * m - 1) / 2;

         if(is_pentagonal(pn+pm) && is_pentagonal(pn-pm))
         {
            found = 1;
            break;
         }
      }
      n++;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 44\n");
   printf("Answer: %d\n", pn-pm);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
