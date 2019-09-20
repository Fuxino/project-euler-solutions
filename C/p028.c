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
