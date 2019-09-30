/* NOTE: This problem is a significantly more challenging version of Problem 81.
 *
 * In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down,
 * is indicated in bold red and is equal to 2297.
 * 
 *       *131* 673  *234* *103*  *18*
 *       *201* *96* *342*  965  *150*
 *        630  803   746  *422* *111*
 *        537  699   497  *121*  956
 *        805  732   524   *37* *331*
 *
 * Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix,
 * from the top left to the bottom right by moving left, right, up, and down.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, dist;
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

   /* Use Dijkstra's algorithm to find the minimum path.*/
   if(dijkstra(matrix, distances, 80, 80, 1, 1, 0) == -1)
   {
      fprintf(stderr, "Error! Dijkstra function returned -1\n");
      return 1;
   }

   dist = distances[79][79];

   for(i = 0; i < 80; i++)
   {
      free(matrix[i]);
      free(distances[i]);
   }

   free(matrix);
   free(distances);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 83\n");
   printf("Answer: %d\n", dist);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
