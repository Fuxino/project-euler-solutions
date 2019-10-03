/* Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.
 *
 * Consider the following two triangles:
 *
 * A(-340,495), B(-153,-910), C(835,-947)
 * X(-175,41), Y(-421,-714), Z(574,-645)
 *
 * It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.
 *
 * Using triangles.txt, a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles
 * for which the interior contains the origin.
 *
 * NOTE: The first two examples in the file represent the triangles in the example given above.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct point
{
   int x;
   int y;
}point;

int main(int argc, char **argv)
{
   int count = 0;
   FILE *fp;
   point p1, p2, p3;
   double a, b, c, elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("triangles.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "triangles.txt");
      return 1;
   }

   /* Using the barycentric coordinates method to determine if (0, 0) is inside the triangles.*/
   while(fscanf(fp, "%d,%d,%d,%d,%d,%d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF)
   {
      a = (double)((p2.y - p3.y) * (-p3.x) + (p3.x - p2.x) * (-p3.y)) /
         ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
      b = (double)((p3.y - p1.y) * (-p3.x) + (p1.x - p3.x) * (-p3.y)) /
         ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
      c = 1 - a - b;

      if(a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
      {
         count++;
      }
   }

   fclose(fp);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 102\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
