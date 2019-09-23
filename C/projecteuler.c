#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "projecteuler.h"

int partition(void **array, int l, int r, int (*cmp)(void *lv, void *rv));

int is_prime(long int num)
{
   long int i, limit;

   if(num <= 3)
   {
      /* If num is 2 or 3 then it's prime.*/
      return num == 2 || num == 3;
   }

   /* If num is divisible by 2 or 3 then it's not prime.*/
   if(num % 2 == 0 || num % 3 == 0)
   {
      return 0;
   }

   /* Any number can have only one prime factor greater than its
    * square root. If we reach the square root and we haven't found
    * any smaller prime factors, then the number is prime.*/
   limit = floor(sqrt(num));

   /* Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
    * If I check all those value no prime factors of the number 
    * will be missed. If a factor is found, the number is not prime
    * and the function returns 0.*/
   for(i = 5; i <= limit; i += 6)
   {
      if(num % i == 0 || num % (i + 2) == 0)
      {
         return 0;
      }
   }

   /* If no factor is found up to the square root of num, num is prime.*/
   return 1;
}

int is_palindrome(int num, int base)
{
   int reverse = 0, tmp;

   tmp = num;

   /* Start with reverse=0, get the rightmost digit of the number using 
    * modulo operation (num modulo base), add it to reverse. Remove the
    * rightmost digit dividing num by the base, shift the reverse left
    * multiplying by the base, repeat until all digits have been inserted
    * in reverse order.*/
   while(tmp > 0)
   {
      reverse *= base;
      reverse += tmp % base;
      tmp /= base;
   }

   /* If the reversed number is equal to the original one, then it's palindrome.*/
   if(num == reverse)
   {
      return 1;
   }

   return 0;
}

long int gcd(long int a, long int b)
{
   /* Euclid's algorithm for the greatest common divisor:
    * gcd(a, 0) = a
    * gcd(a, b) = gcd(b, a modulo b)*/
   if(b == 0)
   {
      return a;
   }

   return gcd(b, a%b);
}

/* Least common multiple algorithm using the greatest common divisor.*/
long int lcm(long int a, long int b)
{
   return a * b / gcd(a, b);
}

/* Recursive function to calculate the least common multiple of more than 2 numbers.*/
long int lcmm(long int *values, int n)
{
   int i;
   long int value;

   /* If there are only two numbers, use the lcm function to calculate the lcm.*/
   if(n == 2)
   {
      return lcm(values[0], values[1]);
   }
   else
   {
      value = values[0];

      for(i = 0; i < n - 1; i++)
      {
         values[i] = values[i+1];
      }

      /* Recursively calculate lcm(a, b, c, ..., n) = lcm(a, lcm(b, c, ..., n)).*/
      return lcm(value, lcmm(values, n-1));
   }
}

/* Function implementing the Sieve or Eratosthenes to generate
 * primes up to a certain number.*/
int *sieve(int n)
{
   int i, j, limit;
   int *primes;

   if((primes = (int *)malloc(n*sizeof(int))) == NULL)
   {
      return NULL;
   }

   /* 0 and 1 are not prime, 2 and 3 are prime.*/
   primes[0] = 0;
   primes[1] = 0;
   primes[2] = 1;
   primes[3] = 1;

   /* Cross out (set to 0) all even numbers and set the odd numbers to 1 (possible prime).*/
   for(i = 4; i < n - 1; i += 2)
   {
      primes[i] = 0;
      primes[i+1] = 1;
   }

   /* If i is prime, all multiples of i smaller than i*i have already been crossed out.
    * if i=sqrt(n), all multiples of i up to n (the target) have been crossed out. So
    * there is no need check i>sqrt(n).*/
   limit = floor(sqrt(n));

   for(i = 3; i <= limit; i += 2)
   {
      /* Find the next number not crossed out, which is prime.*/
      if(primes[i])
      {
         /* Cross out all multiples of i, starting with i*i because any smaller multiple 
          * of i has a smaller prime factor and has already been crossed out. Also, since
          * i is odd, i*i+i is even and has already been crossed out, so multiples are 
          * crossed out with steps of 2*i.*/
         for(j = i * i; j < n; j += 2 * i)
         {
            primes[j] = 0;
         }
      }
   }

   return primes;
}

int count_divisors(int n)
{
   int i, limit, count = 0;

   /* For every divisor below the square root of n, there is a corresponding one
    * above the square root, so it's sufficient to check up to the square root of n
    * and count every divisor twice. If n is a perfect square, the last divisor is
    * wrongly counted twice and must be corrected.*/ 
   limit = floor(sqrt(n));

   for(i = 1; i <= limit; i++)
   {
      if(n % i == 0)
      {
         count += 2;
      }
   }
   
   if(n == limit * limit)
   {
      count--;
   }

   return count;
}

int find_max_path(int **triang, int n)
{
   int i, j;

   for(i = n - 2; i >= 0; i--)
   {
      for(j = 0; j <= i; j++)
      {
         if(triang[i+1][j] > triang[i+1][j+1])
            triang[i][j] += triang[i+1][j];
         else
            triang[i][j] += triang[i+1][j+1];
      }
   }

   return triang[0][0];
}

void insertion_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv))
{
   int i, j;
   void *tmp;
   
   for(i = r; i > l; i--)
   {
      if(cmp(array[i], array[i-1]) < 0)
      {
         tmp = array[i];
         array[i] = array[i-1];
         array[i-1] = tmp;
      }
   }
   for(i = l + 2; i <= r; i++)
   {
      tmp = array[i];
      j = i;

      while(cmp(tmp, array[j-1]) < 0)
      {
         array[j] = array[j-1];
         j--;
      }
      
      array[j] = tmp;
   }
}

int partition(void **array, int l, int r, int (*cmp)(void *lv, void *rv))
{
   int i = l -1, j = r;
   void *pivot, *tmp;
   
   pivot = array[r];
   
   while(1)
   {
      while(cmp(array[++i], pivot) < 0);
      while(cmp(array[--j], pivot) > 0)
      {
         if(j == l)
         {
            break;
         }
      }

      if(j <= i)
      {
         break;
      }

      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
   }

   tmp = array[i];
   array[i] = array[r];
   array[r] = tmp;
   
   return i;
}

void quick_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv))
{
   int i;
   
   if(r - l <= 10)
   {
      insertion_sort(array, l, r, cmp);
      return;
   }
   
   i = partition(array, l, r, cmp);
   quick_sort(array, l, i-1, cmp);
   quick_sort(array, i+1, r, cmp);
}

int is_pandigital(int value, int n)
{
   int *digits;
   int i, digit;

   if((digits = (int *)calloc(n+1, sizeof(int))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      exit(1);
   }

   for(i = 0; i < n && value > 0; i++)
   {
      digit = value % 10;
      if(digit > n)
      {
         return 0;
      }
      digits[digit]++;
      value /= 10;
   }

   if(i < n || value > 0)
   {
      free(digits);
      return 0;
   }

   if(digits[0] != 0)
   {
      free(digits);
      return 0;
   }

   for(i = 1; i <= n; i++)
   {
      if(digits[i] != 1)
      {
         free(digits);
         return 0;
      }
   }

   free(digits);

   return 1;
}

int is_pentagonal(long int n)
{
   double i;

   i = (sqrt(24*n+1) + 1) / 6;

   if(i == (int)i)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
