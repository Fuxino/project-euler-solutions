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

void next_perm(int **perm, int n);
void swap(int **vet, int i, int j);
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
      next_perm(perm, 10);
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

void swap(int **vet, int i, int j)
{
   int *tmp;

   tmp = vet[i];
   vet[i] = vet[j];
   vet[j] = tmp;
}

int compare(void *a, void *b)
{
   int *n1, *n2;

   n1 = (int *)a;
   n2 = (int *)b;

   return *n1 - *n2;
}

/* Implements SEPA (Simple, Efficient Permutation Algorithm)
 * to find the next permutation.*/
void next_perm(int **perm, int n)
{
   int i, key;

   /* Starting from the right of the array, for each pair of values
    * if the left one is smaller than the right, that value is the key.*/
   for(i = n - 2; i >= 0; i--)
   {
      if(compare((void *)perm[i], (void *)perm[i+1]) < 0)
      {
         key = i;
         break;
      }
   }

   /* If no left value is smaller than its right value, the
    * array is in reverse order, i.e. it's the last permutation.*/
   if(i == -1)
   {
      return;
   }

   /* Find the smallest value on the right of the key which is bigger than the key itself,
    * considering that the values at the right of the key are in reverse order.*/
   for(i = key + 1; i < n && compare((void *)perm[i], (void *)perm[key]) > 0; i++);

   /* Swap the value found and the key.*/
   swap(perm, key, i-1);
   /* Sort the values at the right of the key. This is
    * the next permutation.*/
   insertion_sort((void **)perm, key+1, n-1, compare);
}
