/* Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 *
 * As 1 = 1^4 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, j, digit, sum, sum_tot = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Straightforward brute force approach. The limit is chosen considering that
    * 6*9^5=354294, so no number larger than that can be expressed as sum
    * of 5th power of its digits.*/
   for(i = 10; i < 354295; i++)
   {
      j = i;
      sum = 0;

      while(j > 0)
      {
         digit = j % 10;
         sum += (pow(digit, 5));
         j /= 10;
      }

      if(sum == i)
      {
         sum_tot += i;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, problem 30\n");
   printf("Answer: %d\n", sum_tot);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
