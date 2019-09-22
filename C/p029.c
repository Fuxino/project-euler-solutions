#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>
#include "projecteuler.h"

int compare(void *a, void *b);

int main(int argc, char **argv)
{
   mpz_t a;
   mpz_t **powers;
   int i, j, count;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((powers = (mpz_t **)malloc(9801*sizeof(mpz_t *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 9801; i++)
   {
      if((powers[i] = (mpz_t *)malloc(sizeof(mpz_t))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   mpz_init(a);

   for(i = 0; i < 9801; i++)
   {
      mpz_init(*powers[i]);
   }

   for(i = 2; i <= 100; i++)
   {
      mpz_set_ui(a, i);
      for(j = 2; j <= 100; j++)
      {
         mpz_pow_ui(*powers[(i-2)*99+j-2], a, j);
      }
   }

   mpz_clear(a);

   quick_sort((void **)powers, 0, 9800, compare);
   count = 1;

   for(i = 1; i < 9801; i++)
   {
      if(mpz_cmp(*powers[i], *powers[i-1]))
      {
         count++;
      }
   }

   for(i = 0; i < 9801; i++)
   {
      mpz_clear(*powers[i]);
      free(powers[i]);
   }

   free(powers);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 29\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *a, void *b)
{
   mpz_t *n1, *n2;

   n1 = (mpz_t *)a;
   n2 = (mpz_t *)b;

   return mpz_cmp(*n1, *n2);
}
