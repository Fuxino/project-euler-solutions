/* A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed
 * as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int is_abundant(int n);

int main(int argc, char **argv)
{
   int ab_nums[28123], sums[28123] = {0};
   int i, j, sum;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 0; i < 28123; i++)
   {
      /* Find all abundant numbers smaller than 28123.*/
      ab_nums[i] = is_abundant(i+1);
   }

   /* For every abundant number, sum every other abundant number greater 
    * than itself, until the sum exceeds 28123. Record that the resulting
    * number is the sum of two abundant numbers.*/
   for(i = 0; i < 28123; i++)
   {
      if(ab_nums[i])
      {
         for(j = i; j < 28123; j++)
         {
            if(ab_nums[j])
            {
               sum = i + j + 2;

               if(sum <= 28123)
               {
                  sums[sum-1] = 1;
               }
               else
               {
                  break;
               }
            }
         }
      }
   }

   sum = 0;

   /* Sum every number that was not found as a sum of two abundant numbers.*/
   for(i = 0; i < 28123; i++)
   {
      if(!sums[i])
      {
         sum += i + 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 23\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_abundant(int n)
{
   return sum_of_divisors(n, 1) > n;
}
