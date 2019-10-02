/* A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner.
 * By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.
 *
 * However, there are up to three "shortest" path candidates for any given cuboid and the shortest route doesn't always have integer length.
 *
 * It can be shown that there are exactly 2060 distinct cuboids, ignoring rotations, with integer dimensions,
 * up to a maximum size of M by M by M, for which the shortest route has integer length when M = 100.
 * This is the least value of M for which the number of solutions first exceeds two thousand; the number of solutions when M = 99 is 1975.
 *
 * Find the least value of M such that the number of solutions first exceeds one million.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
   int a, b, c, count = 0;
   double d, elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   a = 0;

   while(count <= 1000000)
   {
      a++;

      for(b = 1; b <= a; b++)
      {
         for(c = 1; c <= b; c++)
         {
            /* Unfolding the cuboid, it's obvious that the shortest path
             * is the hypotenuse of a triangle, and the catheti are the
             * longest side of the cubois and the sum of the other two sides.*/
            d = sqrt(a*a+(b+c)*(b+c));

            if(d == (int)d)
               count++;
         }
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 86\n");
   printf("Answer: %d\n", a);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
