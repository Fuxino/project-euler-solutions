/* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
 * contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
   /* Number of letters for numbers from 1 to 19.*/
   int n1_19[19] = {3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
   /* Number of letters for "twenty", "thirty", ..., "ninety".*/
   int n20_90[8] = {6, 6, 5, 5, 5, 7, 6, 6};
   /* Number of letters for "one hundred and", "two hundred and", ...,
    * "nine hundred and".*/
   int n100_900[9] = {13, 13, 15, 14, 14, 13, 15, 15, 14};
   /* Number of letters for 1000.*/
   int n1000 = 11;
   int sum = 0, i, j;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   /* Sum the letters of the first 19 numbers.*/
   for(i = 0; i < 19; i++)
   {
      sum += n1_19[i];
   }

   /* Add the letters of the numbers from 20 to 99.*/ 
   for(i = 0; i < 8; i++)
   {
      /* "Twenty", "thirty", ... "ninety" are used ten times each
       * (e.g. "twenty", "twenty one", "twenty two", ..., "twenty nine").*/
      n20_90[i] *= 10;
      /* Add "one", "two", ..., "nine".*/
      for(j = 0; j < 9; j++)
      {
         n20_90[i] += n1_19[j];
      }
      sum += n20_90[i];
   }

   /* Add the letters of the numbers from 100 to 999.*/
   for(i = 0; i < 9; i++)
   {
      /* "One hundred and", "two hundred and",... are used 100 times each.*/
      n100_900[i] *= 100;
      /* Add "one" to "nineteen".*/
      for(j = 0; j < 19; j++)
      {
         n100_900[i] += n1_19[j];
      }
      /* Add "twenty" to "ninety nine", previously calculated.*/
      for(j = 0; j < 8; j++)
      {
         n100_900[i] += n20_90[j];
      }
      /* "One hundred", "two hundred", ... don't have the "and", so remove 
       * three letters for each of them.*/
      sum += n100_900[i] - 3;
   }

   /* Add "one thousand".*/
   sum += n1000;

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 17\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
