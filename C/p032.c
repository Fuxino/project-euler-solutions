#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *a, void *b);

int main(int argc, char **argv)
{
   int a, b, i, j, k, p, p1, d, sum, n=0;
   int digits[10];
   int **products;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((products = (int **)malloc(100*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 100; i++)
   {
      if((products[i] = (int *)malloc(sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   for(i = 2; i <= 99; i++)
   {
      for(j = 100; j <= 9999; j++)
      {
         a = i;
         b = j;
         p = a * b;

         for(k = 0; k < 10; k++)
         {
            digits[k] = 0;
         }
         
         do
         {
            d = a % 10;
            digits[d]++;
            a /= 10;
         }while(a > 0);

         do
         {
            d = b % 10;
            digits[d]++;
            b /= 10;
         }while(b > 0);

         p1 = p;

         do
         {
            d = p1 % 10;
            digits[d]++;
            p1 /= 10;
         }while(p1 > 0);

         k = 0;

         if(digits[0] == 0)
         {
            for(k = 1; k < 10; k++)
            {
               if(digits[k] > 1 || digits[k] == 0)
               {
                  break;
               }
            }
         }

         if(k == 10)
         {
            *products[n] = p;
            n++;
         }
      }
   }

   quick_sort((void **)products, 0, 99, compare);

   sum = *products[0];

   for(i = 1; i < 100; i++)
   {
      if(*products[i] != *products[i-1])
      {
         sum += *products[i];
      }
   }

   for(i = 0; i < 100; i++)
   {
      free(products[i]);
   }

   free(products);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 32\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *a, void *b)
{
   int *n1, *n2;

   n1 = (int *)a;
   n2 = (int *)b;

   return *n1 - *n2;
}
