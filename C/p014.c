#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int collatz_length(long int n);

int collatz_found[1000000] = {0};

int main(int argc, char **argv)
{
   int i, count, max = 0, max_l = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i< 1000000; i++)
   {
      count = collatz_length(i);
      collatz_found[i] = count;
      
      if(count > max_l)
      {
         max_l = count;
         max = i;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 14\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int collatz_length(long int n)
{
   if(n == 1)
      return 1;

   if(n < 1000000 && collatz_found[n])
      return collatz_found[n];

   if(n % 2 == 0)
      return 1 + collatz_length(n/2);
   else
      return 1 + collatz_length(3*n+1);
}
