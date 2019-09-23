/* By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *    
 *    3
 *   7 4
 *  2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 *               75
 *              95 64
 *             17 47 82
 *            18 35 87 10
 *           20 04 82 47 65
 *          19 01 23 75 03 34
 *         88 02 77 73 07 63 67
 *        99 65 04 28 06 16 70 92
 *       41 41 26 56 83 40 80 70 33
 *      41 48 72 33 47 32 37 16 94 29
 *     53 71 44 65 25 43 91 52 97 51 14
 *    70 11 33 28 77 73 17 78 39 68 17 57
 *   91 71 52 38 17 14 91 43 58 50 27 29 48
 *  63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge 
 * with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)*/

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

   if((triang = (int **)malloc(15*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 1; i <= 15; i++)
   {
      if((triang[i-1] = (int *)malloc(i*sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   if((fp = fopen("triang.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "triang.txt");
      return 1;
   }

   for(i = 1; i <= 15; i++)
   {
      for(j = 0; j < i; j++)
      {
         fscanf(fp, "%d", &triang[i-1][j]);
      }
   }

   fclose(fp);

   /* Use function implemented in projecteuler.c to find the maximum path.*/
   max = find_max_path(triang, 15);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 18\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
