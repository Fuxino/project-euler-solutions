/* We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital 
 * and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int count_digits(int n);

int main(int argc, char **argv)
{
   /* 8- and 9-digit pandigital numbers can't be prime, because 
    * 1+2+...+8=36, which is divisible by 3, and 36+9=45 which is
    * also divisible by 3, and therefore the whole number is divisible
    * by 3. So we can start from the largest 7-digit pandigital number,
    * until we find a prime.*/
   int i = 7654321;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   while(i > 0)
   {
      if(is_pandigital(i, count_digits(i)) && is_prime(i))
      {
         break;
      }
      /*Skipping the even numbers.*/
      i -= 2;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 41\n");
   printf("Answer: %d\n", i);

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
