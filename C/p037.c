#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int is_tr_prime(int n);

int main(int argc, char **argv)
{
   int i = 0, n = 1, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   while(i < 11)
   {
      if(is_tr_prime(n))
      {
         sum += n;
         i++;
      }
      n++;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 37\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_tr_prime(int n)
{
   int i, tmp;

   if(n < 11 || !is_prime(n))
   {
      return 0;
   }

   tmp = n / 10;

   while(tmp > 0)
   {
      if(!is_prime(tmp))
      {
         return 0;
      }
      tmp /= 10;
   }

   i = 10;
   tmp = n % i;

   while(tmp != n)
   {
      if(!is_prime(tmp))
      {
         return 0;
      }
      i *= 10;
      tmp = n % i;
   }

   return 1;
}
