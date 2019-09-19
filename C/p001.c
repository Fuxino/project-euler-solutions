#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i < 1000; i++)
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
