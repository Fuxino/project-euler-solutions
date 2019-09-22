#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, value, n;
   int digits[1000005];
   double elapsed;
   struct timespec start, end;
   
   clock_gettime(CLOCK_MONOTONIC, &start);

   i = 1;
   value = 1;

   while(i <= 1000000)
   {
      if(value < 10)
      {
         digits[i-1] = value;
         i++;
      }
      else if(value < 100)
      {
         digits[i-1] = value / 10;
         digits[i] = value % 10;
         i += 2;
      }
      else if(value < 1000)
      {
         digits[i-1] = value / 100;
         digits[i] = (value / 10) % 10;
         digits[i+1] = value % 10;
         i += 3;
      }
      else if(value < 10000)
      {
         digits[i-1] = value / 1000;
         digits[i] = (value / 100) % 10;
         digits[i+1] = (value / 10) % 10;
         digits[i+2] = value % 10;
         i += 4;
      }
      else if(value < 100000)
      {
         digits[i-1] = value / 10000;
         digits[i] = (value / 1000) % 10;
         digits[i+1] = (value / 100) % 10;
         digits[i+2] = (value / 10) % 10;
         digits[i+3] = value % 10;
         i += 5;
      }
      else if(value < 1000000)
      {
         digits[i-1] = value / 100000;
         digits[i] = (value / 10000) % 10;
         digits[i+1] = (value / 1000) % 10;
         digits[i+2] = (value / 100) % 10;
         digits[i+3] = (value / 10) % 10;
         digits[i+4] = value % 10;
         i += 6;
      }
      value++;
   }

   n = digits[0] * digits[9] * digits[99] * digits[999] * digits[9999] * digits[99999] * digits[999999];

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 40\n");
   printf("Answer: %d\n", n);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
