#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int sum_of_d(int n);

int main(int argc, char **argv)
{
   int i, n, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 2; i < 10000; i++)
   {
      n = sum_of_d(i);
      if(i != n && sum_of_d(n) == i)
      {
         sum += i + n;
      }
   }

   sum /= 2;

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 21\n"); 
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int sum_of_d(int n)
{
   int i, sum = 1, limit;

   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         sum += i;
         if(n != i * i)
         {
            sum += (n / i);
         }
      }
   }

   return sum;
}
