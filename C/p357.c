/* Consider the divisors of 30: 1,2,3,5,6,10,15,30.
 * It can be seen that for every divisor d of 30, d+30/d is prime.
 *
 * Find the sum of all positive integers n not exceeding 100 000 000
 * such that for every divisor d of n, d+n/d is prime.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 100000000

int check_d_nd_prime(int n);

int *primes;

int main(int argc, char **argv)
{
   int i;
   long int sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((primes = sieve(N+2)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   for(i = 2; i <= N; i += 2)
   {
      /* Every number is divisible by 1, so 1+n/1=n+1 must be prime.*/
      if(primes[i+1] && check_d_nd_prime(i))
      {
         sum += i;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 357\n");
   printf("Answer: %ld\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int check_d_nd_prime(int n)
{
   int i, limit;

   /* To get all divisors, it's sufficient to loop up to the square root
    * of the number, because for every divisor d smaller than sqrt(n) n/d
    * is also a divisor larger than sqrt(n).*/
   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         /* We only need to check the property for i and not n/i. 
          * If d=n/i, we would have to check if n/i+n/(n/i)=n/i+i is prime.*/
         if(!primes[i+n/i])
         {
            return 0;
         }
      }
   }

   return 1;
}
