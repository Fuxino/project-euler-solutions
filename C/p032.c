/* We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234,
 * is 1 through 5 pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *a, void *b);

int main(int argc, char **argv)
{
   int a, b, i, j, p, sum, n = 0, num;
   int **products;
   char num_s[10];
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Initially I used a bigger array, but printing the resulting products
    * shows that 10 values are sufficient.*/
   if((products = (int **)malloc(10*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 10; i++)
   {
      if((products[i] = (int *)malloc(sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   /* To get a 1 to 9 pandigital concatenation of the two factors and product,
    * we need to multiply a 1 digit number times a 4 digit numbers (the biggest
    * one digit number 9 times the biggest 3 digit number 999 multiplied give
    * 8991 and the total digit count is 8, which is not enough), or a 2 digit 
    * number times a 3 digit number (the smallest two different 3 digits number,
    * 100 and 101, multiplied give 10100, and the total digit count is 11, which
    * is too many). The outer loop starts at 2 because 1 times any number gives
    * the same number, so its digit will be repeated and the result can't be 
    * pandigital. The nested loop starts from 1234 because it's the smallest 
    * 4-digit number with no repeated digits, and it ends at 4987 because it's
    * the biggest number without repeated digits that multiplied by 2 gives a 
    * 4 digit number. */
   for(i = 2; i < 9; i++)
   {
      for(j = 1234; j < 4987; j++)
      {
         p = i * j;
         sprintf(num_s, "%d%d%d", i, j, p);

         if(strlen(num_s) > 9)
         {
            break;
         }

         num = atoi(num_s);

         if(is_pandigital(num, 9))
         {
            *products[n] = p;
            n++;
         }
      }
   }

   /* The outer loop starts at 12 because 10 has a 0 and 11 has two 1s, so
    * the result can't be pandigital. The nested loop starts at 123 because
    * it's the smallest 3-digit number with no digit repetitions and ends at
    * 833, because 834*12 has 5 digits.*/
   for(i = 12; i < 99; i++)
   {
      for(j = 123; j < 834; j++)
      {
         p = i * j;
         sprintf(num_s, "%d%d%d", i, j, p);

         if(strlen(num_s) > 9)
         {
            break;
         }

         num = atoi(num_s);

         if(is_pandigital(num, 9))
         {
            *products[n] = p;
            n++;
         }
      }
   }
   
   /* Sort the found products to easily see if there are duplicates.*/
   insertion_sort((void **)products, 0, n-1, compare);

   sum = *products[0];

   for(i = 1; i < n; i++)
   {
      if(*products[i] != *products[i-1])
      {
         sum += *products[i];
      }
   }

   for(i = 0; i < 10; i++)
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
