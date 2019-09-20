#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int is_abundant(int n);

int main(int argc, char **argv)
{
   int ab_nums[28123], sums[28123] = {0};
   int i, j, sum;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 0; i < 28123; i++)
   {
      if(i < 11)
      {
         ab_nums[i] = 0;
      }
      else if(is_abundant(i+1))
      {
         ab_nums[i] = 1;
      }
      else
      {
         ab_nums[i] = 0;
      }
   }

   for(i = 0; i < 28123; i++)
   {
      if(ab_nums[i])
      {
         for(j = i; j < 28123; j++)
         {
            if(ab_nums[j])
            {
               sum = i + j + 2;

               if(sum <= 28123)
               {
                  sums[sum-1] = 1;
               }
            }
         }
      }
   }

   sum = 0;

   for(i = 0; i < 28123; i++)
   {
      if(!sums[i])
      {
         sum += i + 1;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 23\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_abundant(int n)
{
   int i, sum = 1, limit;

   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         sum += i;

         if(n != i*i)
         {
            sum += (n / i);
         }
      }
   }

   return sum > n;
}
