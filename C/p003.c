/* The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

long int max_prime_factor(long int num);

int main(int argc, char **argv)
{
   long int res;
   long int num = 600851475143;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Use a function to calculate the largest prime factor.*/
   res = max_prime_factor(num);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 3\n");
   printf("Answer: %ld\n", res);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Recursive approach: if num is prime, return num, otherwise
 * recursively look for the largest prime factor of num divided
 * by its prime factors until only the largest remains.*/
long int max_prime_factor(long int num)
{
   long int i;

   /* Use function defined in projecteuler.c to check if a number is prime.*/
   if(is_prime(num))
   {
      return num;
   }

   /* If num is even, find the largest prime factor of num/2.*/
   if(num % 2 == 0)
   {
      return max_prime_factor(num/2);
   }
   else
   {
      i = 3;
      
      while(1)
      {
         /* If num is divisible by i and i is prime, find largest prime
          * factor of num/i.*/
         if(num % i == 0)
         {
            if(is_prime(i))
            {
               return max_prime_factor(num/i);
            }
         }

         i += 2;
      }
   }

   /* Should never get here.*/
   return -1;
}
