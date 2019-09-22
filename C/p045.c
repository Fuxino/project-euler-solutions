#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int found = 0;
   long int i, n;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   i = 143;

   while(!found)
   {
      i++;
      n = i * (2 * i - 1);
      
      if(is_pentagonal(n))
      {
         found = 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 45\n");
   printf("Answer: %ld\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
