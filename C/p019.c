#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} months;
typedef enum {mon, tue, wed, thu, fri, sat, sun} days;

int main(int argc, char **argv)
{
   int year, i, limit, count = 0;
   double elapsed;
   struct timespec start, end;
   months month;
   days day;

   clock_gettime(CLOCK_MONOTONIC, &start);

   day = mon;
   month = jan;
   year = 1900;

   while(year < 2001)
   {
      if(month == feb)
      {
         if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
         {
            limit = 29;
         }
         else
         {
            limit = 28;
         }
      }
      else if(month == apr || month == jun || month == sep || month == nov)
      {
         limit = 30;
      }
      else
      {
         limit = 31;
      }
      for(i = 1; i <= limit; i++)
      {
         if(year > 1900 && i == 1 && day == sun)
         {
            count++;
         }
         day = (day + 1) % 7;
      }
      month = (month + 1) % 12;
      
      if(month == jan)
      {
         year++;
      }
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 19\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
