/* Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits.
 * For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible.
 * Leading zeroes are not allowed in either n or reverse(n).
 *
 * There are 120 reversible numbers below one-thousand.
 *
 * How many reversible numbers are there below one-billion (109)?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1e9

int reverse(int n);

int main(int argc, char **argv)
{
   int i, s, count = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Brute force approach, sum each number and their reverse and
    * check if there are only odd digits.*/
   for(i = 11; i < N; i++)
   {
      if(i % 10 != 0)
      {
         s = i + reverse(i);

         while(s > 0)
         {
            if((s % 10) % 2 == 0)
            {
               break;
            }
            s /= 10;
         }

         if(s == 0)
         {
            count++;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 145\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int reverse(int n)
{
   int reverse = 0;

   while(n > 0)
   {
      reverse *= 10;
      reverse += n % 10;
      n /= 10;
   }

   return reverse;
}
