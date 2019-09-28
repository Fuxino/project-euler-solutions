/* The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). 
 * In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int check_digits(long int a, long int b);
int count_digits(long int a);

int main(int argc, char **argv)
{
   int count;
   long int i, j, cubes[N];
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Calculate i^3 for all i smaller than 10000.*/
   for(i = 0; i < N; i++)
   {
      cubes[i] = i * i * i;
   }

   /* For each cube, check if there are four other cubes which are also 
    * a permutation of the first cube.*/
   for(i = 0; i < N - 5; i++)
   {
      count = 1;

      /* Stop when the limit has been reached, when 5 values have been found or
       * when j^3 has more digits than i^3 (if they don't have the same digits,
       * they can't be permutations).*/
      for(j = i + 1; j < N && count_digits(cubes[j]) == count_digits(cubes[i]); j++)
      {
         if(check_digits(cubes[i], cubes[j]))
         {
            count++;
         }

         if(count == 5)
         {
            break;
         }
      }

      if(count == 5)
      {
         break;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 62\n");
   printf("Answer: %ld\n", cubes[i]);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int count_digits(long int a)
{
   int count = 0;

   if(a == 0)
   {
      return 1;
   }

   while(a > 0)
   {
      count++;
      a /= 10;
   }

   return count;
}

int check_digits(long int a, long int b)
{
   int i;
   int digits1[10] = {0}, digits2[10] = {0};

   while(a > 0)
   {
      digits1[a%10]++;
      a /= 10;
   }

   while(b > 0)
   {
      digits2[b%10]++;
      b /= 10;
   }

   for(i = 0; i < 10; i++)
   {
      if(digits1[i] != digits2[i])
      {
         return 0;
      }
   }

   return 1;
}
