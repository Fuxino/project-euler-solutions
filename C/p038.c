#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_pandigital(int value, int n);

int main(int argc, char **argv)
{
   int i, j, tmp;
   long int n, max = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i < 10000; i++)
   {
      n = 0;
      j = 1;
      do
      {
         tmp = i * j;
         n += tmp;
         j++;

         if(n > max && is_pandigital(n, 9))
         {
            max = n;
         }
         if(i * j < 10)
         {
            n *= 10;
         }
         else if(i * j < 100)
         {
            n *= 100;
         }
         else if(i * j < 1000)
         {
            n *= 1000;
         }
         else if(i * j < 10000)
         {
            n *= 10000;
         }
         else if(i * j < 100000)
         {
            n *= 100000;
         }
      }while(n <= 987654321);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, Problem 38\n");
   printf("Answer: %ld\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_pandigital(int value, int n)
{
   int *digits;
   int i, digit;

   if((digits = (int *)calloc(n+1, sizeof(int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      exit(1);
   }

   for(i = 0; i < n && value > 0; i++)
   {
      digit = value % 10;
      digits[digit]++;
      value /= 10;
   }

   if(i < n || value > 0)
   {
      free(digits);
      return 0;
   }

   if(digits[0] != 0)
   {
      free(digits);
      return 0;
   }

   for(i = 1; i <= n; i++)
   {
      if(digits[i] != 1)
      {
         free(digits);
         return 0;
      }
   }

   free(digits);

   return 1;
}
