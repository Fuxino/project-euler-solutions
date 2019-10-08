/* Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
 * where each “_” is a single digit.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, found = 0;
   /* Since the square of n has 19 digits, n must be at least 10^9.*/
   long int n = 1e9, p;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   while(!found)
   {
      /* If the square on n ends with 10, n must be divisible by 10.*/
      n += 10;
      p = n * n;

      /* A square divisible by 10 is also divisible by 100.*/
      if(p % 100 != 0)
      {
         continue;
      }

      /* Check if the digits of the square correspond to the given pattern.*/
      i = 9;
      p /= 100;

      while(p > 0)
      {
         if(p % 10 != i)
         {
            break;
         }
         p /= 100;
         i--;
      }

      if(p == 0)
      {
         found = 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 206\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
