/* It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way,
 * but there are many more examples.
 *
 * 12 cm: (3,4,5)
 * 24 cm: (6,8,10)
 * 30 cm: (5,12,13)
 * 36 cm: (9,12,15)
 * 40 cm: (8,15,17)
 * 48 cm: (12,16,20)
 *
 * In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow
 * more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.
 *
 * 120 cm: (30,40,50), (20,48,52), (24,45,51)
 *
 * Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

#define N 1500000

int main(int argc, char **argv)
{
   int i, a, b, c, tmpa, tmpb, tmpc, m, n, count = 0;
   int *l; 
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((l = (int *)calloc(N + 1, sizeof(int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   /* Generate all Pythagorean triplets using Euclid's algorithm:
    * For m>=2 and n<m:
    * a=m*m-n*n
    * b=2*m*n
    * c=m*m+n*n
    * This gives a primitive triple if gcd(m, n)=1 and exactly one
    * of m and n is odd. To generate all the triples, generate all
    * the primitive one and multiply them by i=2,3, ..., n until the
    * perimeter is larger than the limit. The limit for m is 865, because
    * when m=866 even with the smaller n (i.e. 1) the perimeter is greater
    * than the given limit.*/
   for(m = 2; m < 866; m++)
   {
      for(n = 1; n < m; n++)
      {
         if(gcd(m, n) == 1 && ((m % 2 == 0 && n % 2 != 0) || (m % 2 != 0 && n % 2 == 0)))
         {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if(a + b + c <= N)
            {
               l[a+b+c]++;
            }

            i = 2;
            tmpa = i * a;
            tmpb = i * b;
            tmpc = i * c;

            while(tmpa + tmpb + tmpc <= N)
            {
               l[tmpa+tmpb+tmpc]++;

               i++;
               tmpa = i * a;
               tmpb = i * b;
               tmpc = i * c;
            }
         }
      }
   }

   for(i = 0; i <= N; i++)
   {
      if(l[i] == 1)
         count++;
   }

   free(l);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 75\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
