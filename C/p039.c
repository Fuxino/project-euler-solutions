#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   int p, m, n, a, b, c, count, max = 0, res = 0, tmpa, tmpb, tmpc, i;
   int savedc[1000] = {0};
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(p = 12; p <= 1000; p++)
   {
      count = 0;
      a = 0;
      b = 0;
      c = 0;

      for(m = 2; m * m < p; m++)
      {
         for(n = 1; n < m; n++)
         {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if(a + b + c == p && !savedc[c])
            {
               savedc[c] = 1;
               count++;
            }

            i = 2;
            tmpa = a;
            tmpb = b;
            tmpc = c;

            while(tmpa + tmpb + tmpc < p)
            {
               tmpa = a * i;
               tmpb = b * i;
               tmpc = c * i;

               if(tmpa + tmpb + tmpc == p && !savedc[tmpc])
               {
                  savedc[tmpc] = 1;
                  count++;
               }

               i++;
            }
         }
      }

      if(count > max)
      {
         max = count;
         res = p;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 39\n");
   printf("Answer: %d\n", res);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
