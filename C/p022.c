#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projecteuler.h"

int compare(void *string1, void *string2);

int main(int argc, char **argv)
{
   FILE *fp;
   int i, j, n, len, score, sum = 0;
   double elapsed;
   char *line, **names;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("names.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "names.txt");
      return 1;
   }

   fscanf(fp, "%ms", &line);

   fclose(fp);

   len = strlen(line);
   n = 1;

   for(i = 0; i < len; i++)
   {
      if(line[i] == ',')
      {
         n++;
      }
   }

   if((names = (char **)malloc(n*sizeof(char *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   names[0] = strtok(line, ",\"");

   for(i = 1; i < n; i++)
   {
      names[i] = strtok(NULL, ",\"");
   }

   quick_sort((void **)names, 0, n-1, compare);

   for(i = 0; i < n; i++)
   {
      len = strlen(names[i]);
      score = 0;
      for(j = 0; j < len; j++)
      {
         score += names[i][j] - 'A' + 1;
      }
      score *= (i + 1);
      sum += score;
   }

   free(line);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 22\n");
   printf("Answer: %d\n", sum);
   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *string1, void *string2)
{
   char *s1, *s2;

   s1 = (char *)string1;
   s2 = (char *)string2;

   return strcmp(s1, s2);
}
