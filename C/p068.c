/* Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
 *
 *         4
 *          \
 *           \
 *            3
 *           /  \
 *          /    \
 *         1------2------6
 *        /
 *       /
 *      5
 *
 * Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example),
 * each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
 *
 * It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
 *
 * Total	Solution Set
 * 9	4,2,3; 5,3,1; 6,1,2
 * 9	4,3,2; 6,2,1; 5,1,3
 * 10	2,3,5; 4,5,1; 6,1,3
 * 10	2,5,3; 6,3,1; 4,1,5
 * 11	1,4,6; 3,6,2; 5,2,4
 * 11	1,6,4; 5,4,2; 3,2,6
 * 12	1,5,6; 2,6,4; 3,4,5
 * 12	1,6,5; 3,5,4; 2,4,6
 *
 * By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
 *
 * Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string
 * for a "magic" 5-gon ring?
 *
 *             O
 *              \
 *               O
 *             /  \   O
 *            /    \ /
 *           O      O
 *          / \    /
 *         O   O--O---O
 *              \
 *               O
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

int *eval_ring(int **ring, int n);
long int array_to_long(int *n, int len);
int compare(void *a, void *b);

int main(int argc, char **argv)
{
   int i;
   int *eval, **ring;
   long int n, max = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((ring = (int **)malloc(10*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 10; i++)
   {
      if((ring[i] = (int *)malloc(sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
      *ring[i] = i + 1;
   }

   /* Check if the first permutation of values is a possible solution.*/
   eval = eval_ring(ring, 5);

   /* Convert the vector into an integer number.*/
   n = array_to_long(eval, 15);

   if(n > max)
   {
      max = n;
   }
   
   free(eval);

   /* Generate all possible permutations, for each one check if
    * it's a possible solution for the ring and save the maximum.*/
   while(next_permutation((void **)ring, 10, compare) != -1)
   {
      eval = eval_ring(ring, 5);

      n = array_to_long(eval, 15);

      if(n > max)
      {
         max = n;
      }
      
      free(eval);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 68\n");
   printf("Answer: %ld\n", max);

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

/* Function to evaluate the ring. The ring is represented as a vector of 2*n elements,
 * the first n elements represent the external nodes of the ring, the next n elements
 * represent the internal ring.*/
int *eval_ring(int **ring, int n)
{
   int i, j, magic_val, val;
   int *res;

   for(i = 1; i < n; i++)
   {
      /* We need to start from the lowest external node, so if
       * the first element in the vector is not the lowest of 
       * the first n elements (the external elements), the configuration
       * is not a valid one.*/
      if(*ring[i] < *ring[0])
      {
         return NULL;
      }
   }
   
   if((res = (int *)malloc(3*n*sizeof(int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return NULL;
   }

   /* Each group of three must have the same value.*/
   magic_val = *ring[0] + *ring[n] + *ring[n+1];

   for(i = 0, j = 0; i < n; i++, j += 3)
   {
      /* We need to find the maximum 16-digit string, this is
       * possible only if the element "10" is used only once,
       * i.e. if it's one of the external nodes.*/
      if(*ring[n+i] == 10 || *ring[n+(i+1)%n] == 10)
      {
         return NULL;
      }

      /* Check that the value of the current three-element group
       * is the "magic" value.*/
      val = *ring[i] + *ring[n+i] + *ring[n+(i+1)%n];

      if(val != magic_val)
      {
         return NULL;
      }

      /* Save the current element group in the result string.*/
      res[j] = *ring[i];
      res[j+1] = *ring[n+i];
      res[j+2] = *ring[n+(i+1)%n];
   }

   return res;
}

/* Function to convert the vector into a long int.*/
long int array_to_long(int *n, int len)
{
   int i, k = 0;
   long int res = 0;

   if(n == NULL)
   {
      return 0;
   }

   for(i = len - 1; i >= 0; i--)
   {
      res += n[i] * pow(10, k);

      if(n[i] >= 10)
      {
         k += 2;
      }
      else
      {
         k++;
      }
   }

   return res;
}
