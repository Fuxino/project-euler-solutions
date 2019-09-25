/* If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p ≤ 1000, is the number of solutions maximised?*/

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

   /* Start with p=12 (the smallest pythagorean triplet is (3,4,5) and 3+4+5=12.*/
   for(p = 12; p <= 1000; p++)
   {
      count = 0;
      a = 0;
      b = 0;
      c = 0;

      /* Generate pythagorean triplets.*/
      for(m = 2; m * m < p; m++)
      {
         for(n = 1; n < m; n++)
         {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            /* Increase counter if a+b+c=p and the triplet is new,
             * then save the value of c to avoid counting the same 
             * triplet more than once.*/
            if(a + b + c == p && !savedc[c])
            {
               savedc[c] = 1;
               count++;
            }

            i = 2;
            tmpa = a;
            tmpb = b;
            tmpc = c;

            /* Check all the triplets obtained multiplying a, b and c
             * for integer numbers, until the perimeters exceeds p.*/
            while(tmpa + tmpb + tmpc < p)
            {
               tmpa = a * i;
               tmpb = b * i;
               tmpc = c * i;

               /* Increase counter if the new a, b and c give a perimeter=p.*/
               if(tmpa + tmpb + tmpc == p && !savedc[tmpc])
               {
                  savedc[tmpc] = 1;
                  count++;
               }

               i++;
            }
         }
      }

      /* If the current value is greater than the maximum,
       * save the new maximum and the value of p.*/
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
