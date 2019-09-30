/* A common security method used for online banking is to ask the user for three random characters from a passcode.
 * For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.
 *
 * The text file, keylog.txt, contains fifty successful login attempts.
 *
 * Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible
 * secret passcode of unknown length.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *a, void *b);
int check_passcode(int **passcode, int len, int **logins, int n);

int main(int argc, char **argv)
{
   int i, j, keylog, len = 4, found = 0, digits[10] = {0}, passcode_digits[10] = {0}, **passcode, **logins;
   char line[5];
   FILE *fp;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("keylog.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "keylog.txt");
      return 1;
   }

   if((logins = (int **)malloc(50*sizeof(int*))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i = 0; i < 50; i++)
   {
      if((logins[i] = (int *)malloc(3*sizeof(int))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   i = 0;

   while(fscanf(fp, "%s", line) != EOF)
   {
      j = 2;
      keylog = atoi(line);

      while(keylog > 0)
      {
         logins[i][j--] = keylog % 10;
         /* Check which digits are present in the login attempts.*/
         digits[keylog%10]++;
         keylog /= 10;
      }

      i++;
   }

   fclose(fp);

   j = 0;
   for(i = 0; i < 10; i++)
   {
      /* To generate the passcode, only use the digits present in the
       * login attempts.*/
      if(digits[i] > 0)
      {
         passcode_digits[j++] = i;
      }
   }

   while(!found)
   {
      if((passcode = (int **)malloc(len*sizeof(int *))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }

      for(i = 0; i < len; i++)
      {
         if((passcode[i] = (int *)malloc(sizeof(int))) == NULL)
         {
            fprintf(stderr, "Error while allocating memory\n");
            return 1;
         }
         /* For the current length, generate the first passcode with the
          * digits in order.*/
         *passcode[i] = passcode_digits[i];
      }

      /* Check if the passcode is compatible with the login attempts.*/
      if(check_passcode(passcode, len, logins, 50))
      {
         found = 1;
         break;
      }

      /* For the given length, check every permutation until the correct
       * passcode has been found, or all the permutations have been tried.*/
      while(next_permutation((void **)passcode, len, compare) != -1)
      {
         if(check_passcode(passcode, len, logins, 50))
         {
            printf("Project Euler, Problem 79\n");
            printf("Answer: ");
            for(i = 0; i < len; i++)
               printf("%d", *passcode[i]);
            printf("\n");

            found = 1;
            break;
         }
      }

      for(i = 0; i < len; i++)
      {
         free(passcode[i]);
      }
      free(passcode);

      /* If the passcode has not yet been found, try a longer passcode.*/ 
      len++;
   }

   for(i = 0; i < 50; i++)
   {
      free(logins[i]);
   }

   free(logins);
   
   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *a, void *b)
{
   int *n1, *n2;

   n1 = (int *)a;
   n2 = (int *)b;

   return *n1 - *n2;
}

int check_passcode(int **passcode, int len, int **logins, int n)
{
   int i, j, k;

   /* For every login attempt, check if all the digits appear in the
    * passcode in the correct order. Return 0 if a login attempt 
    * incompatible with the current passcode is found.*/
   for(i = 0; i < n; i++)
   {
      k = 0;
      for(j = 0; j < len; j++)
      {
         if(*passcode[j] == logins[i][k])
         {
            k++;
            
            if(k == 3)
            {
               break;
            }
         }
      }

      if(k < 3)
      {
         return 0;
      }
   }

   return 1;
}
