/* In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down,
 * is indicated in bold red and is equal to 2427.
 * 
 *       *131* 673   234   103    18
 *       *201* *96* *342*  965   150
 *        630  803  *746* *422*  111
 *        537  699   497  *121*  956
 *        805  732   524   *37* *331*
 *
 * Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right
 * by only moving right and down.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int sum_paths(int **matrix, int m, int n);

int main(int argc, char **argv)
{
   int i, j, dist;
   int **matrix;
   double elapsed;
   struct timespec start, end;
   FILE *fp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("matrix.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "matrix.txt");
      return 1;
   }

   if((matrix = (int **)malloc(80*sizeof(int *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 80; i++)
   {
      if((matrix[i] = (int *)malloc(80*sizeof(int))) == NULL)
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

   dist = sum_paths(matrix, 80, 80);

   for(i = 0; i < 80; i++)
   {
      free(matrix[i]);
   }

   free(matrix);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 81\n");
   printf("Answer: %d\n", dist);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Get the shortest path starting from the bottom right corner
 * and going backwards.*/
int sum_paths(int **matrix, int m, int n)
{
   int i, j;

   for(i = m - 2; i >= 0; i--)
   {
      matrix[m-1][i] += matrix[m-1][i+1];
      matrix[i][m-1] += matrix[i+1][m-1];
   }

   for(i = m - 2; i >= 0; i--)
   {
      for(j = n - 2; j >= 0; j--)
      {
         if(matrix[i][j+1] > matrix[i+1][j])
         {
            matrix[i][j] += matrix[i+1][j];
         }
         else
         {
            matrix[i][j] += matrix[i][j+1];
         }
      }
   }

   return matrix[0][0];
}
