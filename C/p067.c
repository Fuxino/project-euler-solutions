/* By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 * Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle
 * with one-hundred rows.
 *
 * NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether!
 * If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all.
 * There is an efficient algorithm to solve it. ;o)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, max;
   int **triang;
   double elapsed;
   FILE *fp;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((triang = (int **)malloc(100*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 1; i <= 100; i++)
   {
      if((triang[i-1] = (int *)malloc(i*sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   if((fp = fopen("triangle.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "triangle.txt");
      return 1;
   }

   for(i = 1; i <= 100; i++)
   {
      for(j = 0; j < i; j++)
      {
         fscanf(fp, "%d", &triang[i-1][j]);
      }
   }

   fclose(fp);

   /* Use the function implemented in projecteuler.c to find the maximum path.*/
   max = find_max_path(triang, 100);

   for(i = 0; i < 100; i++)
   {
      free(triang[i]);
   }

   free(triang);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 67\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
