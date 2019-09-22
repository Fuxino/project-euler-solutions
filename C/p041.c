#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int count_digits(int n);

int main(int argc, char **argv)
{
   int i, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 7654321; !found && i > 0; i -= 2)
   {

      if(is_pandigital(i, count_digits(i)) && is_prime(i))
      {
         printf("Project Euler, Problem 41\n");
         printf("Answer: %d\n", i);
         found = 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_digits(int n)
{
   int i = 0;

   while(n > 0)
   {
      i++;
      n /= 10;
   }

   return i;
}
