/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int count = 1, n = 1, target = 10001;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Brute force approach: start with count=1 and check every odd number
    * (2 is the only even prime), if it's prime increment count, until the
    * target prime is reached.*/
   while(count != target)
   {
      n += 2;
      /* Use the function in projecteuler.c to check if a number is prime.*/
      if(is_prime(n))
      {
         count++;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 7\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
