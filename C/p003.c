#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int max_prime_factor(long int num);

int main(int argc, char **argv)
{
   int res;
   long int num = 600851475143;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   res = max_prime_factor(num);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 3\n");
   printf("Answer: %d\n", res);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int max_prime_factor(long int num)
{
   int i, limit;

   if(is_prime(num))
   {
      return num;
   }

   if(num % 2 == 0)
   {
      return max_prime_factor(num/2);
   }
   else
   {
      limit = floor(sqrt(num));

      for(i = 3; i <= limit; i += 2)
      {
         if(num % i == 0)
         {
            if(is_prime((long int)i))
            {
               return max_prime_factor(num/i);
            }
         }
      }
   }

   return -1;
}
