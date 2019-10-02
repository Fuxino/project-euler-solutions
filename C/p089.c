/* For a number written in Roman numerals to be considered valid there are basic rules which must be followed.
 * Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.
 *
 * For example, it would appear that there are at least six ways of writing the number sixteen:
 *
 * IIIIIIIIIIIIIIII
 * VIIIIIIIIIII
 * VVIIIIII
 * XIIIIII
 * VVVI
 * XVI
 *
 * However, according to the rules only XIIIIII and XVI are valid, and the last example is considered to be the most efficient,
 * as it uses the least number of numerals.
 * The 11K text file, roman.txt contains one thousand numbers written in valid, but not necessarily minimal, Roman numerals;
 * see About... Roman Numerals for the definitive rules for this problem.
 *
 * Find the number of characters saved by writing each of these in their minimal form.
 *
 * Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int reduce(char *numeral, int l);

int main(int argc, char **argv)
{
   int i, l, count = 0, count_reduced = 0;
   char *numerals[1000];
   double elapsed;
   struct timespec start, end;
   FILE *fp;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("roman.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "roman.txt");
      return 1;
   }

   /* Get the roman numerals from file, for each find its length, then
    * reduce it and find the new length. At the end, find the difference
    * of the two lengths.*/
   for(i = 0; i < 1000; i++)
   {
      fscanf(fp, "%ms", &numerals[i]);
      l = strlen(numerals[i]);
      count += l;
      l = reduce(numerals[i], l);
      count_reduced += l;
      free(numerals[i]);
   }

   fclose(fp);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 89\n");
   printf("Answer: %d\n", count-count_reduced);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int reduce(char *numeral, int l)
{
   /* DCCCC = CM.*/
   if(strstr(numeral, "DCCCC") != NULL)
   {
      l -= 3;
   }
   /* CCCC = CD.*/
   else if(strstr(numeral, "CCCC") != NULL)
   {
      l -= 2;
   }

   /* LXXXX = XC.*/
   if(strstr(numeral, "LXXXX") != NULL)
   {
      l -= 3;
   }
   /* XXXX = XL.*/
   else if(strstr(numeral, "XXXX") != NULL)
   {
      l -= 2;
   }

   /* VIIII = IX.*/
   if(strstr(numeral, "VIIII") != NULL)
   {
      l -= 3;
   }
   /* IIII = IV.*/
   else if(strstr(numeral, "IIII") != NULL)
   {
      l -= 2;
   }

   return l;
}
