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
   mpz_t a, b;
   char *num;
   size_t size;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(a, 1);
   mpz_init_set_ui(b, 1);

   i = 2;

   while(1)
   {
      mpz_add(a, a, b);
      i++;

      if((size = mpz_sizeinbase(a, 10)) == 1000)
      {
         if((num = (char *)malloc((2+size)*sizeof(char))) == NULL)
         {
            fprintf(stderr, "Error while allocating memory\n");
            return 1;
         }
         gmp_sprintf(num, "%Zd", a);
         size = strlen(num);
         free(num);
         if(size == 1000)
         {
            break;
         }
      }

      mpz_add(b, a, b);
      i++;

      if((size = mpz_sizeinbase(b, 10)) == 1000)
      {
         if((num = (char *)malloc((2+size)*sizeof(char))) == NULL)
         {
            fprintf(stderr, "Error while allocating memory\n");
            return 1;
         }
         gmp_sprintf(num, "%Zd", b);
         size = strlen(num);
         free(num);
         if(size == 1000)
         {
            break;
         }
      }
   }

   mpz_clears(a, b, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 25\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
