#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count(int value, int n, int i);

int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main(int argc, char **argv)
{
   int n;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   n = count(0, 0, 0);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 31\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count(int value, int n, int i)
{
   int j;

   for(j = i; j < 8; j++)
   {
      value += coins[j];

      if(value == 200)
      {
         return n+1;
      }
      else if(value > 200)
      {
         return n;
      }
      else
      {
         n = count(value, n, j);
         value -= coins[j];
      }
   }

   return n;
}
