#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

void selection_sort(mpz_t *v, int n);

int main(int argc, char **argv)
{
   mpz_t a;
   mpz_t powers[9801];
   int i, j, count;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init(a);

   for(i = 0; i < 9801; i++)
   {
      mpz_init(powers[i]);
   }

   for(i = 2; i <= 100; i++)
   {
      mpz_set_ui(a, i);
      for(j = 2; j <= 100; j++)
      {
         mpz_pow_ui(powers[(i-2)*99+j-2], a, j);
      }
   }

   mpz_clear(a);

   selection_sort(powers, 9801);
   count = 1;

   for(i = 1; i < 9801; i++)
   {
      if(mpz_cmp(powers[i], powers[i-1]))
      {
         count++;
      }
   }

   for(i = 0; i < 9801; i++)
   {
      mpz_clear(powers[i]);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 29\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void selection_sort(mpz_t *v, int n)
{
   int i, j, min;
   mpz_t tmp;

   mpz_init(tmp);

   for(i = 0; i < n - 1; i++)
   {
      min = i;
      
      for(j = i + 1; j < n; j++)
      {
         if(mpz_cmp(v[j], v[min])<0)
         {
            min = j;
         }
      }

      mpz_set(tmp, v[min]);
      mpz_set(v[min], v[i]);
      mpz_set(v[i], tmp);
   }
}
