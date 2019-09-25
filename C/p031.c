/* In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *
 * It is possible to make £2 in the following way:
 *
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 * How many different ways can £2 be made using any number of coins?*/

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

/* Simple recursive function that tries every combination.*/
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
