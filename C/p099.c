/* Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 
 * 2^11 = 2048 < 3^7 = 2187.
 *
 * However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.
 *
 * Using base_exp.txt, a 22K text file containing one thousand lines with a base/exponent pair on each line, 
 * determine which line number has the greatest numerical value.
 *
 * NOTE: The first two lines in the file represent the numbers in the example given above.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, max_i = -1, base, exp;
   double curr, max = 0, elapsed;
   struct timespec start, end;
   FILE *fp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("base_exp.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "base_exp.txt");
      return 1;
   }

   for(i = 1; i <= 1000; i++)
   {
      fscanf(fp, "%d,%d", &base, &exp);
      /* If 
       * a^x > b^y
       * log(a^x) > log(b^y)
       * x*log(a) > y*log(b).
       * So for each b^e, calculate e*log(b) and compare these numbers instead.*/
      curr = exp * log(base);

      if(curr > max)
      {
         max = curr;
         max_i = i;
      }
   }

   fclose(fp);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 99\n");
   printf("Answer: %d\n", max_i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
