#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>
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
    * rightmost digit from num dividing num by the base, shift the reverse left
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

/* Same function, using GMP Library for long numbers.*/
int is_palindrome_mpz(mpz_t num, int base)
{
   mpz_t tmp, reverse, rem;

   mpz_inits(tmp, reverse, rem, NULL);
   mpz_set(tmp, num);
   mpz_set_ui(reverse, 0);

   while(mpz_cmp_ui(tmp, 0) > 0)
   {
      mpz_mul_ui(reverse, reverse, base);
      mpz_tdiv_qr_ui(tmp, rem, tmp, base);
      mpz_add(reverse, reverse, rem);
   }

   if(!mpz_cmp(num, reverse))
   {
      mpz_clears(reverse, rem, NULL);
      return 1;
   }
      
   mpz_clears(reverse, rem, NULL);

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

   /* Start from the second to last row and go up.*/
   for(i = n - 2; i >= 0; i--)
   {
      /* For each element in the row, check the two adjacent elements
       * in the row below and sum the larger one to it. At the end,
       * the element at the top will contain the value of the maximum path.*/
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

int sum_of_divisors(int n)
{
   int i, sum = 1, limit;

   /* For each divisor of n smaller than the square root of n,
    * there is another one larger than the square root. If i is 
    * a divisor of n, so is n/i. Checking divisors i up to square
    * root of n and adding both i and n/i is sufficient to sum
    * all divisors.*/
   limit = floor(sqrt(n));

   for(i = 2; i <= limit; i++)
   {
      if(n % i == 0)
      {
         sum += i;
         /* If n is a perfect square, i=limit is a divisor and
          * has to be counted only once.*/
         if(n != i * i)
         {
            sum += (n / i);
         }
      }
   }

   return sum;
}

void swap(void **array, int i, int j)
{
   void *tmp;

   tmp = array[i];
   array[i] = array[j];
   array[j] = tmp;
}

void insertion_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv))
{
   int i, j;
   void *tmp;
  
   /* After this cycle the smallest element will be in the first position of the array.*/ 
   for(i = r; i > l; i--)
   {
      if(cmp(array[i], array[i-1]) < 0)
      {
         swap(array, i, i-1);
      }
   }

   /* For each element in the array (starting from i=2), move it to the left until a 
    * smaller element on its left is found.*/
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
  
   /* Arbitrarily selecting the rightmost element as pivot.*/ 
   pivot = array[r];
   
   while(1)
   {
      /* From the left, loop until an element greater than the pivot is found.*/ 
      while(cmp(array[++i], pivot) < 0);
      /* From the right, loop until an element smaller than the pivot is found
       * or the beginning of the array is reached.*/
      while(cmp(array[--j], pivot) > 0)
      {
         if(j == l)
         {
            break;
         }
      }

      /* If j<=i, array[j], which is smaller than pivot, is already on the left
       * of array[i], which is larger than pivot, so they don't need to be swapped.*/
      if(j <= i)
      {
         break;
      }

      /* If j>i, swap array[i] and array[j].*/
      swap(array, i, j);
   }

   /* Swap array[i] with pivot. All elements on the left of pivot are smaller, all
    * the elements on the right are bigger, so pivot is in the correct position
    * in the sorted array.*/
   swap(array, i, r);
   
   return i;
}

void quick_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv))
{
   int i;
  
   /* If the array is small, it's better to just use a simple insertion_sort algorithm.*/ 
   if(r - l <= 20)
   {
      insertion_sort(array, l, r, cmp);
      return;
   }
  
   /* Partition the array and recursively run quick_sort on the two partitions.*/ 
   i = partition(array, l, r, cmp);
   quick_sort(array, l, i-1, cmp);
   quick_sort(array, i+1, r, cmp);
}

/* Implements SEPA (Simple, Efficient Permutation Algorithm)
 * to find the next permutation.*/
int next_permutation(void **perm, int n, int (*cmp)(void *a, void *b))
{
   int i, key;

   /* Starting from the right of the array, for each pair of values
    * if the left one is smaller than the right, that value is the key.*/
   for(i = n - 2; i >= 0; i--)
   {
      if(cmp(perm[i], perm[i+1]) < 0)
      {
         key = i;
         break;
      }
   }

   /* If no left value is smaller than its right value, the
    * array is in reverse order, i.e. it's the last permutation.*/
   if(i == -1)
   {
      return -1;
   }

   /* Find the smallest value on the right of the key which is bigger than the key itself,
    * considering that the values at the right of the key are in reverse order.*/
   for(i = key + 1; i < n && cmp(perm[i], perm[key]) > 0; i++);

   /* Swap the value found and the key.*/
   swap(perm, key, i-1);
   /* Sort the values at the right of the key. This is
    * the next permutation.*/
   insertion_sort(perm, key+1, n-1, cmp);

   return 0;
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

   /* A number n is pentagonal if p=(sqrt(24n+1)+1)/6 is an integer.
    * In this case, n is the pth pentagonal number.*/
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

/* Function implementing the iterative algorithm taken from Wikipedia
 * to find the continued fraction for sqrt(S). The algorithm is as
 * follows:
 * 
 * m_0=0
 * d_0=1
 * a_0=floor(sqrt(n))
 * m_(n+1)=d_n*a_n-m_n
 * d_(n+1)=(S-m_(n+1)^2)/d_n
 * a_(n+1)=floor((sqrt(S)+m_(n+1))/d_(n+1))=floor((a_0+m_(n+1))/d_(n+1))
 * if a_i=2*a_0, the algorithm ends.*/
int period_cf(int n)
{
   int mn = 0, mn1, dn = 1, dn1, a0, an, an1, count = 0;

   a0 = floor(sqrt(n));
   an = a0;
   
   do
   {
      mn1 = dn * an - mn;
      dn1 = (n - mn1 * mn1) / dn;
      an1 = floor((a0+mn1)/dn1);
      mn = mn1;
      dn = dn1;
      an = an1;
      count++;
   }while(an != 2 * a0);

   return count;
}
