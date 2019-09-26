/* A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *a, void *b);

int main(int argc, char **argv)
{
   int i, res[10];
   int **perm;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((perm = (int **)malloc(10*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 10; i++)
   {
      if((perm[i] = (int *)malloc(sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
      *perm[i] = i;
   }

   for(i = 0; i < 999999; i++)
   {
      /* Function that generates permutations in lexicographic order.
       * Finish when the 1000000th is found.*/
      next_permutation((void **)perm, 10, compare);
   }

   for(i = 0; i < 10; i++)
   {
      res[i] = *perm[i];
      free(perm[i]);
   }

   free(perm);

   clock_gettime(CLOCK_MONOTONIC, &end);

   printf("Project Euler, Problem 24\n");
   printf("Answer: ");

   for(i = 0; i < 10; i++)
   {
      printf("%d", res[i]);
   }

   printf("\n");

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

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
