/* The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors
 * of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.
 *
 * Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220,
 * forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.
 *
 * Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:
 *
 * 12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)
 *
 * Since this chain returns to its starting point, it is called an amicable chain.
 *
 * Find the smallest member of the longest amicable chain with no element exceeding one million.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000000

int sum_proper_divisors(int i);
int sociable_chain(int i, int start, int *min, int l);

/* Vector to save the current chain values. I started with a longer vector,
 * but no chain is longer than 100 elements, so this is sufficient.*/
int c[100];
int divisors[N] = {0};

int main(int argc, char **argv)
{
   int i, min = 0, min_tmp, length, l_max = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   for(i = 4; i <= N; i++)
   {
      /* Calculate the divisors of i and save it. Ii is equal to the sum of its proper divisors, 
       * the length of the chain is 1 and we don't need to check it.*/
      if((divisors[i] = sum_proper_divisors(i)) == i)
      {
         continue;
      }
      else
      {
         min_tmp = i;
         length = sociable_chain(i, i, &min_tmp, 0);
      }
      
      if(length > l_max)
      {
         l_max = length;
         min = min_tmp;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 95\n");
   printf("Answer: %d\n", min);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int sum_proper_divisors(int n)
{
   int i, limit, sum = 1;

   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         sum += i;
         sum += n / i;
      }
   }

   if(n == limit * limit)
   {
      sum -= limit;
   }

   return sum;
}

/* Function to recursively find the length of the chain.*/
int sociable_chain(int i, int start, int *min, int l)
{
   int n;

   /* Save current number in the chain.*/
   c[l] = i;

   /* If we reached 1, the chain will never return go anywhere.*/
   if(i == 1)
   {
      return -1;
   }

   /* Calculate the divisors of i, or retrieve the value if previously calculated.*/
   if(divisors[i] != 0)
   {
      n = divisors[i];
   }
   else
   {
      n = sum_proper_divisors(i);
      divisors[i] = n;
   }
   
   /* We are looking for chain where no value is greater than 1000000.*/
   if(n > N)
   {
      return -1;
   }

   /* If the next number in the chain is equal to the starting one, the chain is finished.*/
   if(n == start)
   {
      return l + 1;
   }

   /* Check if n is equal to another value of the chain different from start. If it is, the
    * chain is stuck in a loop that will not return to the starting number.*/
   for(i = l; i > 0; i--)
   {
      if(n == c[i])
      {
         return -1;
      }
   }

   /* If the next value is smaller than the minimum value of the chain,
    * update the minimum.*/
   if(n < *min)
   {
      *min = n;
   }

   return sociable_chain(n, start, min, l+1);
}
