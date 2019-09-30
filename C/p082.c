/* NOTE: This problem is a more challenging version of Problem 81.
 *
 * The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column,
 * and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
 *
 *        131  673  *234* *103*  *18*
 *       *201* *96* *342*  965   150
 *        630  803   746   422   111
 *        537  699   497   121   956
 *        805  732   524    37   331 
 *
 * Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix, from the left column to the right column.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, min_path=INT_MAX;
   int **matrix, **distances;
   double elapsed;
   struct timespec start, end;
   FILE *fp;

   clock_gettime(CLOCK_MONOTONIC, &start);
   
   if((fp = fopen("matrix.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "matrix.txt");
      return 1;
   }

   if((matrix = (int **)malloc(80*sizeof(int *))) == NULL ||
         (distances = (int **)malloc(80*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 80; i++)
   {
      if((matrix[i] = (int *)malloc(80*sizeof(int))) == NULL ||
            (distances[i] = (int *)malloc(80*sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   for(i = 0; i < 80; i++)
   {
      for(j = 0; j < 80; j++)
      {
         fscanf(fp, "%d,", &matrix[i][j]);
      }
   }

   fclose(fp);

   /* Use Dijkstra's algorithm starting from all possible nodes
   * in the first column.*/
   for(i = 0; i < 80; i++)
   {
      if(dijkstra(matrix, distances, 80, 80, 1, 0, i) == -1)
      {
         fprintf(stderr, "Error! Dijkstra function returned -1\n");
         return 1;
      }

      /* For the current starting node, check if there is an ending node
       * with a smaller path cost than the current minimum.*/
      for(j = 0; j < 80; j++)
      {
         if(distances[j][79] < min_path)
         {
            min_path = distances[j][79];
         }
      }
   }

   for(i = 0; i < 80; i++)
   {
      free(matrix[i]);
      free(distances[i]);
   }

   free(matrix);
   free(distances);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 82\n");
   printf("Answer: %d\n", min_path);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
