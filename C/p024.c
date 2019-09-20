#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void next_perm(int *perm, int n);
void swap(int *vet, int i, int j);
void sort(int *vet, int i, int n);

int main(int argc, char **argv)
{
   int i, perm[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 0; i < 999999; i++)
   {
      next_perm(perm, 10);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   printf("Project Euler, Problem 24\n");
   printf("Answer: ");

   for(i = 0; i < 10; i++)
   {
      printf("%d", perm[i]);
   }

   printf("\n");

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

void next_perm(int *perm, int n)
{
   int i, j, min = n, min_idx, flag = 0;

   for(i = 0; i < n - 1; i++)
   {
      if(perm[i] < perm[i+1])
      {
         flag=1;
         break;
      }
   }

   if(!flag)
   {
      return;
   }

   for(i = n - 2; perm[i] > perm[i+1]; i--);

   for(j = i + 1; j < n; j++)
   {
      if(perm[j] > perm[i] && perm[j] < min)
      {
         min = perm[j];
         min_idx = j;
      }
   }

   swap(perm, i, min_idx);
   sort(perm, i+1, n);
}

void swap(int *vet, int i, int j)
{
   int tmp;

   tmp = vet[i];
   vet[i] = vet[j];
   vet[j] = tmp;
}

void sort(int *vet, int i, int j)
{
   int a, b, tmp;

   for(a=i+1; a<j; a++)
   {
      tmp=vet[a];
      b=a-1;
      while(b>=i && vet[b]>tmp)
      {
         vet[b+1]=vet[b];
         b--;
      }
      vet[b+1]=tmp;
   }
}
