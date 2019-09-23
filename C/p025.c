/* The Fibonacci sequence is defined by the recurrence relation:
 *
 * Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * Hence the first 12 terms will be:
 * F1 = 1
 * F2 = 1
 * F3 = 2
 * F4 = 3
 * F5 = 5
 * F6 = 8
 * F7 = 13
 * F8 = 21
 * F9 = 34
 * F10 = 55
 * F11 = 89
 * F12 = 144
 *
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the index of the first term in the Fibonacci sequence to contain 1000 digits?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int i;
   double elapsed;
   struct timespec start, end;
   mpz_t f1, f2, fn;
   char *num;
   size_t size;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(f1, 1);
   mpz_init_set_ui(f2, 1);
   mpz_init(fn);

   i = 2;

   while(1)
   {
      /* Use the GMP Library to calculate the Fibonacci numbers.*/
      mpz_add(fn, f1, f2);
      i++;

      /* The function mpz_sizeinbase gives the number of digits of
       * the number in the given base, but the result is either exact
       * or one too big. To check the exact size, the number is
       * converted to string and the strlen function is used.*/
      if((size = mpz_sizeinbase(fn, 10)) >= 1000)
      {
         if((num = (char *)malloc((2+size)*sizeof(char))) == NULL)
         {
            fprintf(stderr, "Error while allocating memory\n");
            return 1;
         }
         gmp_sprintf(num, "%Zd", fn);
         size = strlen(num);
         free(num);
         if(size == 1000)
         {
            break;
         }
      }

      mpz_set(f1, f2);
      mpz_set(f2, fn);
   }

   mpz_clears(f1, f2, fn, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 25\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
