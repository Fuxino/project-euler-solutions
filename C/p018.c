#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sum_triangle(int **triang, int n, int i, int j, int sum);

int max = 0; 

int main(int argc, char **argv)
{
   int i, j;
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

   sum_triangle(triang, 15, 0, 0, 0);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 18\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void sum_triangle(int **triang, int n, int i, int j, int sum)
{
   if(i == n)
   {
      if(sum > max)
      {
         max = sum;
      }
      return;
   }

   sum_triangle(triang, n, i+1, j, sum+triang[i][j]);
   sum_triangle(triang, n, i+1, j+1, sum+triang[i][j]);

}
