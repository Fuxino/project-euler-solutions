#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int n1_19[19] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
   int n20_90[8] = {6, 6, 5, 5, 5, 7, 6, 6};
   int n100_900[9] = {13, 13, 15, 14, 14, 13, 15, 15, 14};
   int n1000 = 11;
   int sum = 0, i, j;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 0; i < 19; i++)
   {
      sum += n1_19[i];
   }

   for(i = 0; i < 8; i++)
   {
      n20_90[i] *= 10;
      for(j = 0; j < 9; j++)
      {
         n20_90[i] += n1_19[j];
      }
      sum += n20_90[i];
   }

   for(i = 0; i < 9; i++)
   {
      n100_900[i] *= 100;
      for(j = 0; j < 19; j++)
      {
         n100_900[i] += n1_19[j];
      }
      for(j = 0; j < 8; j++)
      {
         n100_900[i] += n20_90[j];
      }
      sum += n100_900[i] - 3;
   }

   sum += n1000;

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 17\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
