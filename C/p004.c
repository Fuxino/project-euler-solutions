#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_palindrome(int num, int base);

int main(int argc, char **argv)
{
   int i, j, max = 0, num;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 999; i >= 100; i--)
   {
      for(j = i; j >= 100; j--)
      {
         num = i * j;
         if(num > max && is_palindrome(num, 10))
         {
            max = num;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 4\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_palindrome(int num, int base)
{
   int reverse = 0, tmp;

   tmp = num;

   while(tmp > 0)
   {
      reverse *= base;
      reverse += tmp % base;
      tmp /= base;
   }

   if(num == reverse)
   {
      return 1;
   }

   return 0;
}
