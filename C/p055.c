/* If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
 *
 * Not all numbers produce palindromes so quickly. For example,
 *
 * 349 + 943 = 1292,
 * 1292 + 2921 = 4213
 * 4213 + 3124 = 7337
 *
 * That is, 349 took three iterations to arrive at a palindrome.
 *
 * Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome
 * through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, 
 * we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either 
 * (i) become a palindrome in less than fifty iterations, or,
 * (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown
 * to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
 *
 * Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
 *
 * How many Lychrel numbers are there below ten-thousand?
 *
 * NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>
#include "projecteuler.h"

int is_lychrel(mpz_t n);

int main(int argc, char **argv)
{
   int i, count = 0;
   double elapsed;
   struct timespec start, end;
   mpz_t n;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(n);

   /* For each number, use the is_lychrel function to check if the number
    * is a Lychrel number.*/
   for(i = 1; i < 10000; i++)
   {
      mpz_set_ui(n, i);

      if(is_lychrel(n))
         count++;
   }

   mpz_clear(n);
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 55\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_lychrel(mpz_t n)
{
   int i;
   mpz_t tmp, reverse, rem;

   mpz_inits(tmp, reverse, rem, NULL);
   mpz_set(tmp, n);

   /* Run for 50 iterations.*/
   for(i = 0; i < 50; i++)
   {
      mpz_set_ui(reverse, 0);

      /* Find the reverse of the given number.*/ 
      while(mpz_cmp_ui(tmp, 0) > 0)
      {
         mpz_mul_ui(reverse, reverse, 10);
         mpz_tdiv_qr_ui(tmp, rem, tmp, 10);
         mpz_add(reverse, reverse, rem);
      }

      /* Add the reverse to the original number.*/
      mpz_add(tmp, n, reverse);

      /* If the sum is a palindrome, the number is not a Lychrel number.*/
      if(is_palindrome_mpz(tmp, 10))
      {
         mpz_clears(tmp, reverse, rem, NULL);
         return 0;
      }

      mpz_set(n, tmp);
   }

   mpz_clears(tmp, reverse, rem, NULL);

   return 1;
}
