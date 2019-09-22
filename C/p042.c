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

   words[0] = strtok(line, ",\"");

   for(i = 1; i < n; i++)
   {
      words[i] = strtok(NULL, ",\"");
   }

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
