/* The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:
 *
 * 1! + 4! + 5! = 1 + 24 + 120 = 145
 *
 * Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are
 * only three such loops that exist:
 *
 * 169 → 363601 → 1454 → 169
 * 871 → 45361 → 871
 * 872 → 45362 → 872
 *
 * It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,
 *
 * 69 → 363600 → 1454 → 169 → 363601 (→ 1454)
 * 78 → 45360 → 871 → 45361 (→ 871)
 * 540 → 145 (→ 145)
 *
 * Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number
 * below one million is sixty terms.
 *
 * How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int factorial(int n);
int len_chain(int n);

int factorials[10] = {0};
int chains[N] = {0};

int main(int argc, char **argv)
{
   int i, count = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Simple brute force approach, for every number calculate
    * the length of the chain.*/
   for(i = 3; i < N; i++)
   {
      if(len_chain(i) == 60)
      {
         count++;
      }
   }
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 74\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Recursively calculate the factorial, of a number, saving the result
 * so that it can be reused later.*/
int factorial(int n)
{
   if(n == 0 || n == 1)
   {
      return 1;
   }
   else if(factorials[n] != 0)
   {
      return factorials[n];
   }
   else
   {
      factorials[n]=n*factorial(n-1);
      return factorials[n];
   }
}

int len_chain(int n)
{
   int i, count = 0, finished = 0, value, tmp;
   int chain[60];

   value = n;
   chain[count] = value;

   while(!finished)
   {
      tmp = 0;
      count++;

      /* Generate the next number of the chain by taking
       * the digits of the current value, calculating the
       * factorials and adding them.*/
      while(value != 0)
      {
         tmp += factorial(value % 10);
         value /= 10;
      }

      /* If the chain length for the new value has already been
       * calculated before, use the saved value (only chains for
       * values smaller than N are saved).*/
      if(tmp < N && chains[tmp] != 0)
      {
         return count + chains[tmp];
      }

      value = tmp;

      /* If the current value is already present in the chain,
       * the chain is finished.*/
      for(i = 0; i < count; i++)
      {
         if(chain[i] == value)
         {
            finished = 1;
         }
      }

      chain[count] = value;
   }

   chains[n] = count;

   return count;
}
