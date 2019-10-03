/* Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
 *
 * Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
 *
 * We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
 *
 * Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy.
 * In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
 *
 * Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
 *
 * Find the least number for which the proportion of bouncy numbers is exactly 99%.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int is_bouncy(int n);

int main(int argc, char **argv)
{
   int i = 100, n_bouncy = 0;
   double ratio = 0.0, elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   while(1)
   {
      if(is_bouncy(i))
      {
         n_bouncy++;
      }

      ratio = (double)n_bouncy / i;
      
      if(ratio == 0.99)
      {
         break;
      }
     
      i++;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 112\n");
   printf("Answer: %d\n", i);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

/* Check if the number is bouncy.*/
int is_bouncy(int n)
{
   int i = 0, l;
   char n_string[100];

   sprintf(n_string, "%d", n);

   l = strlen(n_string);

   /* Ignore consecutive equal digits.*/
   while(i < l - 1 && n_string[i] == n_string[i+1])
   {
      i++;
   }

   /* If all the digits are the same, the number is not bouncy.*/
   if(i == l - 1)
   {
      return 0;
   }

   /* If the first two different digits are increasing, if a successive
    * digit smaller than the previous digit is found, the number is bouncy.*/
   if(n_string[i] < n_string[i+1])
   {
      for(; i < l - 1; i++)
      {
         if(n_string[i] > n_string[i+1])
         {
            return 1;
         }
      }
   }

   /* If the first two different digits are decreasing, if a successive
    * digit larger than the previous digit is found, the number is bouncy.*/
   if(n_string[i] > n_string[i+1])
   {
      for(; i < l - 1; i++)
      {
         if(n_string[i] < n_string[i+1])
         {
            return 1;
         }
      }
   }

   return 0;
}
