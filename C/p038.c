/* Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 * 192 × 1 = 192
 * 192 × 2 = 384
 * 192 × 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated
 * product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int main(int argc, char **argv)
{
   int i, j, tmp;
   long int n, max = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* A brute force approach is used, starting with 1 and multiplying
    * the number by 1, 2 etc., concatenating the results, checking if 
    * it's 1 to 9 pandigital, and going to the next number when the
    * concatenated result is greater than the greatest 9 digit pandigital
    * value. The limit is set to 10000, since 1*10000=10000, 2*10000=20000 and
    * concatenating this two numbers a 10-digit number is obtained.*/
   for(i = 1; i < 10000; i++)
   {
      n = 0;
      j = 1;
      do
      {
         tmp = i * j;
         n += tmp;
         j++;

         if(n > max && is_pandigital(n, 9))
         {
            max = n;
         }
         if(i * j < 10)
         {
            n *= 10;
         }
         else if(i * j < 100)
         {
            n *= 100;
         }
         else if(i * j < 1000)
         {
            n *= 1000;
         }
         else if(i * j < 10000)
         {
            n *= 10000;
         }
         else if(i * j < 100000)
         {
            n *= 100000;
         }
      }while(n <= 987654321);
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 38\n");
   printf("Answer: %ld\n", max);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
