/* Triangle, square, pentagonal, hexagonal, heptagonal, and octagonal numbers are all figurate (polygonal) numbers and are generated
 * by the following formulae:
 *
 * Triangle	 	   P3,n=n(n+1)/2	 	1, 3, 6, 10, 15, ...
 * Square	 	   P4,n=n2	 	      1, 4, 9, 16, 25, ...
 * Pentagonal	 	P5,n=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
 * Hexagonal	 	P6,n=n(2n−1)	 	1, 6, 15, 28, 45, ...
 * Heptagonal	 	P7,n=n(5n−3)/2	 	1, 7, 18, 34, 55, ...
 * Octagonal	 	P8,n=n(3n−2)	 	1, 8, 21, 40, 65, ...
 *
 * The ordered set of three 4-digit numbers: 8128, 2882, 8281, has three interesting properties.
 *
 * The set is cyclic, in that the last two digits of each number is the first two digits of the next number (including the last number with the first).
 * Each polygonal type: triangle (P3,127=8128), square (P4,91=8281), and pentagonal (P5,44=2882), is represented by a different number in the set.
 * This is the only set of 4-digit numbers with this property.
 *
 * Find the sum of the only ordered set of six cyclic 4-digit numbers for which each polygonal type: triangle, square, pentagonal,
 * hexagonal, heptagonal, and octagonal, is represented by a different number in the set.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_set(int step, int *sum);

int polygonal[6][10000] = {0};
int chain[6], flags[6] = {0};

int main(int argc, char **argv)
{
   int i, n, sum = 0;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   i = 1;
   n = 1;

   /* Generate all triangle numbers smaller than 10000*/
   do
   {
      polygonal[0][n] = 1;
      i++;
      n = i * (i + 1) / 2;
   }while(n < 10000);

   i = 1;
   n = 1;

   /* Generate all square numbers smaller than 10000.*/
   do
   {
      polygonal[1][n] = 1;
      i++;
      n = i * i;
   }while(n < 10000);

   i = 1;
   n = 1;

   /* Generate all pentagonal numbers smaller than 10000.*/
   do
   {
      polygonal[2][n] = 1;
      i++;
      n = i * (3 * i - 1) / 2;
   }while(n < 10000);

   i = 1;
   n = 1;

   /* Generate all hexagonal numbers smaller than 10000.*/
   do
   {
      polygonal[3][n] = 1;
      i++;
      n = i * (2 * i - 1);
   }while(n < 10000);

   i = 1;
   n = 1;

   /* Generate all heptagonal numbers smaller than 10000.*/
   do
   {
      polygonal[4][n] = 1;
      i++;
      n = i * (5 * i - 3) / 2;
   }while(n < 10000);

   i = 1;
   n = 1;

   /* Generate all octagonal numbers smaller than 10000.*/
   do
   {
      polygonal[5][n] = 1;
      i++;
      n = i * (3 * i - 2);
   }while(n < 10000);

   /* Find the requested set of numbers.*/
   if(find_set(0, &sum) == 0)
   {
      printf("Set not found\n");
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 61\n");
   printf("Answer: %d\n", sum);
   
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Recursive function to find the required set. It finds a polygonal number,
 * check if it can be part of the chain, then use recursion to find the next
 * number. If a solution can't be found with the current numbers, it uses
 * backtracking and tries the next polygonal number.*/
int find_set(int step, int *sum)
{
   int i, j;

   /* Use one polygonal number per type, starting from triangular.*/
   for(i = 0; i < 6; i++)
   {
      /* If the current type has not been used yet, try it.*/
      if(!flags[i])
      {
         /* Set a flag to record that the current polygonal type has been used.*/
         flags[i] = 1;

         /* Start from 1010 because numbers finishing with 00, 01, ..., 09 can't
          * be part of the chain.*/
         for(j = 1010; j < 10000; j++)
         {
            /* If the number doesn't finish with 00, 01, ..., 09 and is poligonal,
             * try adding it to the chain and add its value to the total sum.*/
            if(j % 100 > 9 && polygonal[i][j])
            {
               /* If it's the first number, just add it as first step in the chain.*/
               if(step == 0)
               {
                  chain[step] = j;
                  *sum += j;

                  /* Recursively try to add other numbers to the chain. If a solution
                   * is found, return 1.*/
                  if(find_set(step+1, sum))
                  {
                     return 1;
                  }

                  /* If a solution was not found, backtrack, subtracting the value of
                   * the number from the total.*/
                  *sum -= j;
               }
               /* If this is the last step and the current number can be added to the chain,
                * add it, update the sum and return 1. A solution has been found.*/
               else if(step == 5 && j % 100 == chain[0] / 100 && j / 100 == chain[step-1] % 100)
               {
                  chain[step] = j;
                  *sum += j;
                  return 1;
               }
               /* For every other step, add the number to the chain if possible, then recursively
                * try to add other numbers.*/
               else if(step < 5 && j / 100 == chain[step-1] % 100)
               {
                  chain[step] = j;
                  *sum += j;

                  if(find_set(step+1, sum))
                  {
                     return 1;
                  }

                  /* If a solution was not found, backtrack.*/
                  *sum -= j;
               }
            }
         }

         /* Remove the flag for the current polygonal type.*/
         flags[i] = 0;
      }
   }

   return 0;
}
