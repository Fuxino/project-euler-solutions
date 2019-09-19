#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, sum_squares = 0, square_sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i <= 100; i++)
   {
      sum_squares += i*i;
      square_sum += i;
   }

   square_sum *= square_sum;

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 6\n");
   printf("Answer: %d\n", square_sum-sum_squares);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
