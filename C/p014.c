/* The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem),
 * it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int collatz_length(long int n);

int collatz_found[N] = {0};

int main(int argc, char **argv)
{
   int i, count, max = 0, max_l = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 1; i < N; i++)
   {
      /* For each number from 1 to 1000000, find the length of the sequence
       * and save its value, so that it can be used for the next numbers.*/
      count = collatz_length(i);
      collatz_found[i] = count;
      
      if(count > max_l)
      {
         max_l = count;
         max = i;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 14\n");
   printf("Answer: %d\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Recursive function to calculate the Collatz sequence for n.
 * If n is even, Collatz(n)=1+Collatz(n/2), if n is odd
 * Collatz(n)=1+Collatz(3*n+1).*/
int collatz_length(long int n)
{
   if(n == 1)
      return 1;

   /* If Collatz(n) has been previously calculated,
    * just return the value.*/
   if(n < N && collatz_found[n])
      return collatz_found[n];

   if(n % 2 == 0)
      return 1 + collatz_length(n/2);
   else
      return 1 + collatz_length(3*n+1);
}
