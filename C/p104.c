/* The Fibonacci sequence is defined by the recurrence relation:
*
* F_n = F_n−1 + F_n−2, where F_1 = 1 and F_2 = 1.
* It turns out that F_541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital
* (contain all the digits 1 to 9, but not necessarily in order). And F_2749, which contains 575 digits, is the first Fibonacci number
* for which the first nine digits are 1-9 pandigital.
*
* Given that F_k is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>
#include "projecteuler.h"

void fib_calc(mpz_t fib, int n);

int main(int argc, char **argv)
{
   unsigned int i = 2, j, fib1 = 1, fib2 = 1, fibn, fib_int, found = 0;
   char *fib_str;
   double elapsed;
   struct timespec start, end;
   mpz_t fib;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(fib);

   while(!found)
   {
      /* Calculate the next Fibonacci number modulo 10^9 and check if the result is 1-9 pandigital.*/
      fibn = (fib1 + fib2) % 1000000000;
      fib1 = fib2;
      fib2 = fibn;
      i++;
      
      /* If the last 9 digits of fib_n are pandigital, calculate the ith Fibonacci number using
       * the matrix representation.*/
      if(is_pandigital(fibn, 9))
      {
         fib_calc(fib, i);
         fib_str = mpz_get_str(NULL, 10, fib);

         fib_int = 0;

         for(j = 0; j < 9; j++)
         {
            fib_int *= 10;
            fib_int += fib_str[j] - '0';
         }

         if(is_pandigital(fib_int, 9))
         {
            found = 1;
         }

         free(fib_str);
      }
   }

   mpz_clear(fib);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 104\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void fib_calc(mpz_t fib, int n)
{
   int i;
   mpz_t tmp, tmp00, tmp01, tmp10, tmp11;
   mpz_t fib_matrix_base[2][2], fib_matrix[2][2];

   mpz_init_set_ui(fib_matrix_base[0][0], 1);
   mpz_init_set_ui(fib_matrix_base[0][1], 1);
   mpz_init_set_ui(fib_matrix_base[1][0], 1);
   mpz_init_set_ui(fib_matrix_base[1][1], 0);
   mpz_init_set_ui(fib_matrix[0][0], 1);
   mpz_init_set_ui(fib_matrix[0][1], 1);
   mpz_init_set_ui(fib_matrix[1][0], 1);
   mpz_init_set_ui(fib_matrix[1][1], 0);
   mpz_inits(tmp, tmp00, tmp01, tmp10, tmp11, NULL);

   for(i = 0; i < n - 1; i++)
   {
      mpz_mul(tmp00, fib_matrix[0][0], fib_matrix_base[0][0]);
      mpz_mul(tmp, fib_matrix[0][1], fib_matrix_base[1][0]);
      mpz_add(tmp00, tmp00, tmp);
      mpz_mul(tmp01, fib_matrix[0][0], fib_matrix_base[0][1]);
      mpz_mul(tmp, fib_matrix[0][1], fib_matrix_base[1][1]);
      mpz_add(tmp01, tmp01, tmp);
      mpz_mul(tmp10, fib_matrix[1][0], fib_matrix_base[0][0]);
      mpz_mul(tmp, fib_matrix[1][1], fib_matrix_base[1][0]);
      mpz_add(tmp10, tmp10, tmp);
      mpz_mul(tmp11, fib_matrix[1][0], fib_matrix_base[0][1]);
      mpz_mul(tmp, fib_matrix[1][1], fib_matrix_base[1][1]);
      mpz_add(tmp11, tmp11, tmp);
      mpz_set(fib_matrix[0][0], tmp00);
      mpz_set(fib_matrix[0][1], tmp01);
      mpz_set(fib_matrix[1][0], tmp10);
      mpz_set(fib_matrix[1][1], tmp11);
   }

   mpz_set(fib, fib_matrix[0][1]);

   mpz_clears(tmp, tmp00, tmp01, tmp10, tmp11, fib_matrix_base[0][0],
         fib_matrix_base[0][1], fib_matrix_base[1][0], fib_matrix_base[1][1],
         fib_matrix[0][0], fib_matrix[1][0], fib_matrix[1][1], NULL);
}
