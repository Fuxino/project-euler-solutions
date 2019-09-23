/* You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/

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
      /* February has 29 days on leap years, otherwise 28. Leap years are those
       * divisible by 4, but not if they're divisible by 100, except when they're
       * divisible by 400.*/
      if(month == feb)
      {
         if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
         {
            limit = 29;
         }
         else
         {
            limit = 28;
         }
      }
      /* April, June, September and November have 30 days.*/
      else if(month == apr || month == jun || month == sep || month == nov)
      {
         limit = 30;
      }
      /* All other months have 31 days.*/
      else
      {
         limit = 31;
      }
      /* Loop on every day of the month.*/
      for(i = 1; i <= limit; i++)
      {
         /* If it's the first day of the month and it's Sunday, increase
          * counter, except if year=1900 (we need to count Sundays from
          * 1901 to 2000.*/
         if(year > 1900 && i == 1 && day == sun)
         {
            count++;
         }
         /* Change day of the week.*/
         day = (day + 1) % 7;
      }
      /* At the end of the month, go to next month.*/
      month = (month + 1) % 12;

      /* If we're back to january, increase the year.*/
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
