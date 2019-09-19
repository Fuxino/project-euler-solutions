#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i = 0, finished = 0, count, triang = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   while(!finished)
   {
      i++;
      triang += i;
      count = count_divisors(triang);
      
      if(count > 500)
      {
         finished = 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 12\n");   
   printf("Answer: %d\n", triang);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
