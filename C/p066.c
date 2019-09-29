/* Consider quadratic Diophantine equations of the form:
 *
 * x^2 – Dy^2 = 1
 *
 * For example, when D=13, the minimal solution in x is 649^2 – 13×180^2 = 1.
 *
 * It can be assumed that there are no solutions in positive integers when D is square.
 *
 * By finding minimal solutions in x for D = {2, 3, 5, 6, 7}, we obtain the following:
 *
 * 3^2 – 2×2^2 = 1
 * 2^2 – 3×1^2 = 1
 * 9^2 – 5×4^2 = 1
 * 5^2 – 6×2^2 = 1
 * 8^2 – 7×3^2 = 1
 *
 * Hence, by considering minimal solutions in x for D ≤ 7, the largest x is obtained when D=5.
 *
 * Find the value of D ≤ 1000 in minimal solutions of x for which the largest value of x is obtained.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gmp.h>
#include "projecteuler.h"

int is_square(int n);

int main(int argc, char **argv)
{
   int i, max_d = -1;
   mpz_t x, max;
   double elapsed;
   struct timespec start, end;
   
   clock_gettime(CLOCK_MONOTONIC, &start);

//   mpz_init(x);
   mpz_init_set_ui(max, 0);

   for(i = 2; i <= 1000; i++)
   {
      if(!is_square(i))
      {
         /* Solve the Diophantine equation x^2-D*y^2=1 (Pell equation)*/
         if(pell_eq(i, x) == -1)
         {
            fprintf(stderr, "Error! Pell_eq function failed\n");
            return 1;
         }
         
         if(mpz_cmp(x, max) > 0)
         {
            mpz_set(max, x);
            max_d = i;
         }
      }
   }

   mpz_clears(x, max, NULL);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 66\n");
   printf("Answer: %d\n", max_d);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_square(int n)
{
   int m;
   double p;

   p = sqrt(n);
   m = p;

   if(p == m)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

