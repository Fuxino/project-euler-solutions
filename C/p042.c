/* The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
 * For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words,
 * how many are triangle words?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int is_triang(int n);

int main(int argc, char **argv)
{
   int i, j, n, len, value, count = 0;
   char *line, **words;
   double elapsed;
   FILE *fp;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("words.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "words.txt");
      return 1;
   }

   fscanf(fp, "%ms", &line);

   fclose(fp);

   n = 1;
   len = strlen(line);

   /* Count the words.*/
   for(i = 0; i < len; i++)
   {
      if(line[i] == ',')
      {
         n++;
      }
   }

   if((words = (char **)malloc(n*sizeof(char *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   /* Save the words in an array of strings.*/
   words[0] = strtok(line, ",\"");

   for(i = 1; i < n; i++)
   {
      words[i] = strtok(NULL, ",\"");
   }

   /* For each word, calculate its value and check if it's a triangle number.*/
   for(i = 0; i < n; i++)
   {
      value = 0;
      len = strlen(words[i]);

      for(j = 0; j < len; j++)
      {
         value += (words[i][j] - 'A' + 1);
      }

      if(is_triang(value))
      {
         count++;
      }
   }

   free(line);
   free(words);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec-start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 42\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int is_triang(int n)
{
   int i, j;

   for(i = 1, j = 1; j <= n; i++, j += i)
   {
      if(n == j)
      {
         return 1;
      }
   }

   return 0;
}
