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
