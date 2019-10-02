/* A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
 *
 * For example,
 *
 * 44 → 32 → 13 → 10 → 1 → 1
 * 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
 *
 * Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that
 * EVERY starting number will eventually arrive at 1 or 89.
 *
 * How many starting numbers below ten million will arrive at 89?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int chains[N] = {0};

int chain(int n);

int main(int argc, char **argv)
{
   int i, count;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i < N; i++)
   {
      /* Simply create a chain for each number and check if it ends at 89, saving
       * the result so it can be reused.*/
      if((chains[i] = chain(i)) == 89)
      {
         count++;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 92\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Recursively find the chain for n.*/
int chain(int n)
{
   int tmp = 0, digit;

   /* If n=1 or n=89, we reached the end of the chain.*/
   if(n == 1)
   {
      return 1;
   }

   if(n == 89)
   {
      return 89;
   }

   /* If the chain for the current n has already been found,
    * return the value.*/
   if(chains[n] != 0)
   {
      return chains[n];
   }

   while(n > 0)
   {
      digit = n % 10;
      tmp += digit * digit;
      n /= 10;
   }

   return chain(tmp);
}
