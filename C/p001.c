/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Simple brute-force approach: try every number between 3 and 999,
    * check if it's a multiple of 3 or 5, if yes add it to the total.*/
   for(i = 3; i < 1000; i++)
   {
      if (i % 3 == 0 || i % 5 == 0)
      {
         sum += i;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 1\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
