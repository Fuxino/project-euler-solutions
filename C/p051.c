/* By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten
 * generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this
 * family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime
 * value family.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int count_digit(int n, int d);
int replace(int n);

int *primes;

int main(int argc, char **argv)
{
   int i, found = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* N set to 1000000 as a reasonable limit, which turns out to be enough.*/
   if((primes = sieve(N)) == NULL)
   {
      fprintf(stderr, "Error! Sieve function returned NULL\n");
      return 1;
   }

   /* Checking only odd numbers with at least 4 digits.*/
   for(i = 1001; i < N; i += 2)
   {
      /* The family of numbers needs to have at least one of 0, 1 or 2 as
       * repeated digits, otherwise we can't get a 8 number family (there 
       * are only 7 other digits). Also, the number of repeated digits must
       * be 3, otherwise at least 3 resulting numbers will be divisible by 3.
       * So the smallest number of this family must have three 0s, three 1s or
       * three 2s.*/
      if(count_digit(i, 0) >= 3 || count_digit(i, 1) >= 3 ||
            count_digit(i, 2) >= 3)
      {
      /* If i is prime, try replacing digits, if obtaining 8 primes, then 
       * this is the result.*/
         if(primes[i] && replace(i) == 8)
         {
            break;
         }
      }
   }

   free(primes);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 51\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_digit(int n, int d)
{
   int count = 0;

   while(n > 0)
   {
      if(n % 10 == d)
      {
         count++;
      }
      n /= 10;
   }

   return count;
}

int replace(int n)
{
   int i, j, k, w, l, count, max = 0, s_to_n;
   char n_to_s[7];

   sprintf(n_to_s, "%d", n);
   l = strlen(n_to_s);

   for(i = 0; i < l - 3; i++)
   {
      for(j = i + 1; j < l - 2; j++)
      {
         /* Replacing the last digit can't give 8 primes, because at least
          * six of the numbers obtained will be divisible by 2 and/or 5.*/
         for(k = j + 1; k < l - 1; k++)
         {
            count = 0;

            for(w = 0; w < 10; w++)
            {
               if(i == 0 && w == 0)
               {
                  continue;
               }

               sprintf(n_to_s, "%d", n);
               n_to_s[i] = w + '0';
               n_to_s[j] = w + '0';
               n_to_s[k] = w + '0';
               s_to_n = atoi(n_to_s);

               if(primes[s_to_n])
               {
                  if(count == 0 && s_to_n != n)
                  {
                     continue;
                  }

                  count++;
               }
            }

            if(count > max)
            {
               max = count;
            }
         }
      }
   }

   return max;
}
