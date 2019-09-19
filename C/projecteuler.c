#include <stdlib.h>
#include <math.h>
#include "projecteuler.h"

int is_prime(long int num)
{
   int i, limit;

   if(num <= 3)
   {
      return num == 2 || num == 3;
   }

   if(num % 2 == 0 || num % 3 == 0)
   {
      return 0;
   }

   limit = floor(sqrt(num));

   for(i = 5; i <= limit; i += 6)
   {
      if(num % i == 0 || num % (i + 2) == 0)
      {
         return 0;
      }
   }

   return 1;
}

long int gcd(long int a, long int b)
{
   long int tmp;

   while(b != 0)
   {
      tmp = b;
      b = a % b;
      a = tmp;
   }

   return a;
}

long int lcm(long int a, long int b)
{
   return a * b / gcd(a, b);
}

long int lcmm(long int *values, int n)
{
   int i;
   long int value;

   if(n == 2)
   {
      return lcm(values[0], values[1]);
   }
   else
   {
      value = values[0];

      for(i = 0; i < n - 1; i++)
      {
         values[i] = values[i+1];
      }

      return lcm(value, lcmm(values, n-1));
   }
}

int *sieve(int n)
{
   int i, j, limit;
   int *primes;

   if((primes = (int *)malloc(n*sizeof(int))) == NULL)
   {
      return NULL;
   }

   primes[0] = 0;
   primes[1] = 0;
   primes[2] = 1;
   primes[3] = 1;

   for(i = 4; i < n - 1; i += 2)
   {
      primes[i] = 0;
      primes[i+1] = 1;
   }

   limit = floor(sqrt(n));

   for(i = 3; i < limit; i += 2)
   {
      if(primes[i])
      {
         for(j = i * i; j < n; j += 2 * i)
         {
            primes[j] = 0;
         }
      }
   }

   return primes;
}

int count_divisors(int n)
{
   int i, limit, count = 0;

   limit = floor(sqrt(n));

   for(i = 1; i < limit; i++)
   {
      if(n % i == 0)
      {
         count += 2;
      }

      if(n == limit * limit)
      {
         count--;
      }
   }

   return count;
}
