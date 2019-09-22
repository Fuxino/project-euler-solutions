#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(int *v, int i, int n);
void swap(int *a, int *b);
int has_property(int *v);

long int sum = 0;

int main(int argc, char **argv)
{
   int n[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   permute(n, 0, 9);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 43\n");
   printf("Answer: %ld\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void permute(int *v, int i, int n)
{
   int j;

   if(i == n)
   {
      if(has_property(v))
      {
         sum += v[0] * 1e9 + v[1] * 1e8 + v[2] * 1e7 + v[3] * 1e6 + v[4] * 1e5 + v[5] * 1e4 + v[6] * 1e3 + v[7] * 1e2 + v[8] * 1e1 + v[9];
      }
   }
   else
   {
      for(j = i; j <= n; j++)
      {
         swap((v+i), (v+j));
         permute(v, i+1, n);
         swap((v+i), (v+j));
      }
   }
}

void swap(int *a, int *b)
{
   int tmp;

   tmp = *a;
   *a = *b;
   *b = tmp;
}

int has_property(int *v)
{
   long int value;

   value = v[1] * 100 + v[2] * 10 + v[3];

   if(value % 2 != 0)
   {
      return 0;
   }

   value = v[2] * 100 + v[3] * 10 + v[4];

   if(value % 3 != 0)
   {
      return 0;
   }

   value = v[3] * 100 + v[4] * 10 + v[5];

   if(value % 5 != 0)
   {
      return 0;
   }

   value = v[4] * 100 + v[5] * 10 + v[6];

   if(value % 7 != 0)
   {
      return 0;
   }

   value = v[5] * 100 + v[6] * 10 + v[7];

   if(value % 11 != 0)
   {
      return 0;
   }

   value = v[6] * 100 + v[7] * 10 + v[8];

   if(value %13 != 0)
   {
      return 0;
   }

   value = v[7] * 100 + v[8] * 10 + v[9];

   if(value % 17 != 0)
   {
      return 0;
   }

   return 1;
}
