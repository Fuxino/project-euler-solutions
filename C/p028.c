/* Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1001

int main(int argc, char **argv)
{
   int i, j, step = 0, limit = N * N, sum = 1;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Starting with the central 1, it's easy to see that the next four numbers in the diagonal
    * are 1+2, 1+2+2, 1+2+2+2 and 1+2+2+2+2, then for the next four number the step is increased
    * by two, so from 9 to 9+4, 9+4+4 etc, for the next four number the step is again increased
    * by two, and so on. We go on until the value is equal to N*N, with N=1001 for this problem.*/
   for(i = 0, j = 1; j < limit; i = (i + 1) % 4)
   {
      if(i == 0)
      {
         step += 2;
      }

      j += step;
      sum += j;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 28\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
