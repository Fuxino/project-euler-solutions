/* It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 *
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int have_same_digits(int a, int b);

int main(int argc, char **argv)
{
   int i;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   i = 1;

   /* Brute force approach, try every integer number until the desired one is found.*/
   while(1)
   {
      if(have_same_digits(i, 2*i) && have_same_digits(i, 3*i) && have_same_digits(i, 4*i) &&
            have_same_digits(i, 5*i) && have_same_digits(i, 6*i))
      {
         break;
      }

      i++;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 52\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int have_same_digits(int a, int b)
{
   int i;
   int digits1[10] = {0}, digits2[10] = {0};

   /* Get digits of a.*/
   while(a > 0)
   {
      digits1[a%10]++;
      a /= 10;
   }

   /* Get digits of b.*/
   while(b > 0)
   {
      digits2[b%10]++;
      b /= 10;
   }

   /* If they're not the same, return 0.*/
   for(i = 0; i < 10; i++)
   {
      if(digits1[i] != digits2[i])
      {
         return 0;
      }
   }

   return 1;
}
