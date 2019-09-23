/* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner
 * How many such routes are there through a 20×20 grid?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   double elapsed;
   struct timespec start, end;
   mpz_t count, tmp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Using a combinatorial solution: in a 20x20 grid there will always be
    * 20 movements to the right and 20 movements down, that can be represented
    * as a string of Rs and Ds. The number of routes is the number of combinations.
    * This is obtained calculating n!/(k!*(n-k)!), where n=40 and k=20. The GMP
    * Library is used to calculate the factorials.*/
   mpz_inits(count, tmp, NULL);
   mpz_fac_ui(count, 40);
   mpz_fac_ui(tmp, 20);
   mpz_mul(tmp, tmp, tmp);
   mpz_tdiv_q(count, count, tmp);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 15\n");
   gmp_printf("Answer: %Zd\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   mpz_clears(count, tmp, NULL);

   return 0;
}
