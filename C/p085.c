/* By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles.
 *
 * Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv)
{
   int i, j, n, diff, min_diff = INT_MAX, area;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i < 100; i++)
   {
      for(j = 1; j <= i; j++)
      {
         /* In a 2x3 grid, we can take rectangles of height 2 in 3 ways
          * (two rectangles of height one and one of height 2). For the
          * width, can take 6 rectangles (3 of width 1, 2 of width 2 and
          * 1 of width 3). The total is 6x3=18 rectagles. 
          * Extending to mxn, we can take (m+m-1+m-2+...+1)x(n+n-1+n-2+...+1)= 
          * m(m+1)/2*n(n+1)/2=m(m+1)*n(n+1)/4 rectangles.*/
         n = ( i * (i + 1) * j * (j + 1)) / 4;
         diff = abs(2000000 - n);

         if(diff < min_diff)
         {
            min_diff = diff;
            area = i * j;
         }
      }
   }
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 85\n");
   printf("Answer: %d\n", area);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
