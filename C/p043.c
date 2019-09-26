/* The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a
 * rather interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 * d2d3d4=406 is divisible by 2
 * d3d4d5=063 is divisible by 3
 * d4d5d6=635 is divisible by 5
 * d5d6d7=357 is divisible by 7
 * d6d7d8=572 is divisible by 11
 * d7d8d9=728 is divisible by 13
 * d8d9d10=289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *a, void *b);
int has_property(int **n);

int main(int argc, char **argv)
{
   int i;
   int **n;
   long int sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((n = (int **)malloc(10*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }
 
   for(i = 0; i < 10; i++)
   {
      if((n[i] = (int *)malloc(sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
      *n[i] = i;
   }

   /* Find the next permutation and check if it has the required property.
    * Repeat until all the permutations have been found.*/
   while(next_permutation((void **)n, 10, compare) != -1)
   {
      if(has_property(n))
      {
         sum += *n[0] * 1e9 + *n[1] * 1e8 + *n[2] * 1e7 + *n[3] * 1e6 + *n[4] * 1e5 +
                *n[5] * 1e4 + *n[6] * 1e3 + *n[7] * 1e2 + *n[8] * 1e1 + *n[9];
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 43\n");
   printf("Answer: %ld\n", sum);

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

/* Function to check if the value has the desired property.*/
int has_property(int **n)
{
   long int value;

   value = *n[1] * 100 + *n[2] * 10 + *n[3];

   if(value % 2 != 0)
   {
      return 0;
   }

   value = *n[2] * 100 + *n[3] * 10 + *n[4];

   if(value % 3 != 0)
   {
      return 0;
   }

   value = *n[3] * 100 + *n[4] * 10 + *n[5];

   if(value % 5 != 0)
   {
      return 0;
   }

   value = *n[4] * 100 + *n[5] * 10 + *n[6];

   if(value % 7 != 0)
   {
      return 0;
   }

   value = *n[5] * 100 + *n[6] * 10 + *n[7];

   if(value % 11 != 0)
   {
      return 0;
   }

   value = *n[6] * 100 + *n[7] * 10 + *n[8];

   if(value %13 != 0)
   {
      return 0;
   }

   value = *n[7] * 100 + *n[8] * 10 + *n[9];

   if(value % 17 != 0)
   {
      return 0;
   }

   return 1;
}
