#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int fib0 = 1, fib1 = 2, fib2, sum = 2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   fib2 = fib0 + fib1;

   while(fib2 <= 4000000)
   {
      if(fib2 % 2 == 0)
      {
         sum += fib2;
      }

      fib0 = fib1;
      fib1 = fib2;
      fib2 = fib0 + fib1;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 2\n");   
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
