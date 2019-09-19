#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int a, b, c, m, n, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(m = 2; found == 0; m++)
   {
      for(n = 1; n < m; n++)
      {
         a = m * m - n * n;
         b = 2 * m * n;
         c = m * m + n * n;

         if(a + b + c == 1000)
         {
            found = 1;
            break;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 9\n");
   printf("Answer: %d\n", a*b*c);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
