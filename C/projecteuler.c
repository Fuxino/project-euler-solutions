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

int sum_of_divisors(int n, int proper)
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
         sum += n / i;
      }
   }
   
   /* If n is a perfect square, i=limit is a divisor and
    * has to be counted only once.*/
   if(n == limit * limit)
   {
      sum -= limit;
   }

   if(!proper)
   {
      sum += n;
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
int *build_sqrt_cont_fraction(int i, int *period, int l)
{
   int mn = 0, mn1, dn = 1, dn1, a0, an, an1, count = 0, j;
   int *fraction;

   if((fraction = (int *)malloc(l*sizeof(int))) == NULL)
   {
      return NULL;
   }

   j = 0;
   a0 = floor(sqrt(i));
   an = a0;
   fraction[j] = an;
   j++;

   do
   {
      mn1 = dn * an - mn;
      dn1 = (i - mn1 * mn1)/ dn;
      an1 = floor((a0+mn1)/dn1);
      mn = mn1;
      dn = dn1;
      an = an1;
      count++;
      fraction[j] = an;
      j++;
   }while(an != 2 * a0);

   fraction[j] = -1;

   *period = count;

   return fraction;
}

/* Function to solve the Diophantine equation in the form x^2-Dy^2=1
 * (Pell equation) using continued fractions.*/
int pell_eq(int d, mpz_t x)
{
   int found = 0, j, period;
   mpz_t n1, n2, n3, d1, d2, d3, sol, tmp;
   int *fraction;

   /* Find the continued fraction for sqrt(d).*/
   if((fraction = build_sqrt_cont_fraction(d, &period, 100)) == NULL)
   {
      return -1;
   }

   /* Calculate the first convergent of the continued fraction.*/
   mpz_init_set_ui(n1, 0);
   mpz_init_set_ui(n2, 1);
   mpz_init_set_ui(d1, 1);
   mpz_init_set_ui(d2, 0);
   mpz_inits(n3, d3, sol, tmp, NULL);

   j = 0;
   mpz_mul_ui(n3, n2, fraction[j]);
   mpz_add(n3, n3, n1);
   mpz_mul_ui(d3, d2, fraction[j]);
   mpz_add(d3, d3, d1);
   j++;

   /* Check if x=n, y=d solve the equation x^2-Dy^2=1.*/
   mpz_mul(sol, n3, n3);
   mpz_mul(tmp, d3, d3);
   mpz_mul_ui(tmp, tmp, d);
   mpz_sub(sol, sol, tmp);

   if(mpz_cmp_ui(sol, 1) == 0)
   {
      mpz_set(x, n3);
      found = 1;
      free(fraction);
      mpz_clears(n1, n2, n3, d1, d2, d3, sol, tmp, NULL);
   }

   /* Until a solution is found, calculate the next convergent
    * and check if x=n and y=d solve the equation.*/
   while(!found)
   {
      mpz_set(n1, n2);
      mpz_set(n2, n3);
      mpz_set(d1, d2);
      mpz_set(d2, d3);
      mpz_mul_ui(n3, n2, fraction[j]);
      mpz_add(n3, n3, n1);
      mpz_mul_ui(d3, d2, fraction[j]);
      mpz_add(d3, d3, d1);

      mpz_mul(sol, n3, n3);
      mpz_mul(tmp, d3, d3);
      mpz_mul_ui(tmp, tmp, d);
      mpz_sub(sol, sol, tmp);

      if(mpz_cmp_ui(sol, 1) == 0)
      {
         mpz_set(x, n3);
         found = 1;
         free(fraction);
         mpz_clears(n1, n2, n3, d1, d2, d3, sol, tmp, NULL);
      }

      j++;

      if(fraction[j] == -1)
      {
         j = 1;
      }
   }

   return 0;
}

/* Function to check if a number is semiprime. Parameters include
 * pointers to p and q to return the factors values and a list of
 * primes.*/
int is_semiprime(int n, int *p, int *q, int *primes)
{
   int i, limit;

   /* If n is prime, it's not semiprime.*/
   if(primes[n])
   {
      return 0;
   }

   /* Check if n is semiprime and one of the factors is 2.*/
   if(n % 2 == 0)
   {
      if(primes[n/2])
      {
         *p = 2;
         *q = n / 2;
         return 1;
      }
      else
      {
         return 0;
      }
   }
   /* Check if n is semiprime and one of the factors is 3.*/
   else if(n % 3 == 0)
   {
      if(primes[n/3])
      {
         *p = 3;
         *q = n / 3;
         return 1;
      }
      else
      {
         return 0;
      }
   }

   /*Any number can have only one prime factor greater than its
   square root, so we can stop checking at this point.*/
   limit = floor(sqrt(n));

   /* Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
    * If I check all those value no prime factors of the number 
    * will be missed. For each of these possible primes, check if 
    * they are prime, then if the number is semiprime with using
    * that factor.*/
   for(i = 5; i <= limit; i += 6)
   {
      if(primes[i] && n % i == 0)
      {
         if(primes[n/i])
         {
            *p = i;
            *q = n / i;
            return 1;
         }
         else
         {
            return 0;
         }
      }
      else if(primes[i+2] && n % (i + 2) == 0)
      {
         if(primes[n/(i+2)])
         {
            *p = i + 2;
            *q = n / (i + 2);
            return 1;
         }
         else
         {
            return 0;
         }
      }
   }

   return 0;
}

/* If n=pq is semiprime, phi(n)=(p-1)(q-1)=pq-p-q+1=n-(p+4)+1
 * if p!=q. If p=q (n is a square), phi(n)=n-p.*/
int phi_semiprime(int n, int p, int q)
{
   if(p == q)
   {
      return n - p;
   }
   else
   {
      return n - (p + q) + 1;
   }
}

/* Function to calculate phi(n) for any n. If n is prime, phi(n)=n-1,
 * is n is semiprime, use the above function. In any other case,
 * phi(n)=n*prod(1-1/p) for every distinct prime p that divides n.*/
int phi(int n, int *primes)
{
   int i, p, q, limit;
   double ph = (double)n;

   /* If n is prime, phi(n)=n-1*/
   if(primes[n])
   {
      return n - 1;
   }

   /* If n is semiprime, use above function.*/
   if(is_semiprime(n, &p, &q, primes))
   {
      return phi_semiprime(n, p, q);
   }

   /* If 2 is a factor of n, multiply the current ph (which now is n)
    * by 1-1/2, then divide all factors 2.*/
   if(n % 2 == 0)
   {
      ph *= (1.0 - 1.0 / 2.0);

      do
      {
         n /= 2;
      }while(n % 2 == 0);
   }

   /* If 3 is a factor of n, multiply the current ph by 1-1/3,
    * then divide all factors 3.*/
   if(n % 3 == 0)
   {
      ph *= (1.0 - 1.0 / 3.0);

      do
      {
         n /= 3;
      }while(n % 3 == 0);
   }

   /*Any number can have only one prime factor greater than its
    * square root, so we can stop checking at this point and deal
    * with the only factor larger than sqrt(n), if present, at the end.*/
   limit = floor(sqrt(n));

   /* Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
    * If I check all those value no prime factors of the number 
    * will be missed. For each of these possible primes, check if 
    * they are prime, then check if the number divides n, in which
    * case update the current ph.*/
   for(i = 5; i <= limit; i += 6)
   {
      if(primes[i])
      {
         if(n % i == 0)
         {
            ph *= (1.0 - 1.0 / i);

            do
            {
               n /= i;
            }while(n % i == 0);
         }
      }
      if(primes[i+2])
      {
         if(n % (i + 2) == 0)
         {
            ph *= (1.0 - 1.0 /(i + 2));

            do
            {
               n /= (i + 2);
            }while(n % (i + 2) == 0);
         }
      }
   }

   /* After dividing all prime factors smaller than sqrt(n), n is either 1
    * or is equal to the only prime factor greater than sqrt(n). In this
    * second case, we need to update ph with the last prime factor.*/
   if(n > 1)
   {
      ph *= (1.0 - 1.0 / n);
   }

   return (int)ph;
}

/* Function implementing the partition function.*/
long int partition_fn(int n, long int *partitions, int mod)
{
   int k, limit;
   long int res = 0;

   /* The partition function for negative numbers is 0 by definition.*/
   if(n < 0)
   {
      return 0;
   }

   /* The partition function for zero is 1 by definition.*/
   if(n == 0)
   {
      partitions[n] = 1;

      return 1;
   }

   /* If the partition for the current n has already been calculated, return the value.*/
   if(partitions[n] != 0)
   {
      return partitions[n];
   }

   k = -ceil((sqrt(24*n+1)-1)/6);
   limit = floor((sqrt(24*n+1)+1)/6);

   while(k <= limit)
   {
      if(k != 0)
      {
         res += pow(-1, k+1) * partition_fn(n-k*(3*k-1)/2, partitions, mod);
      }
      k++;
   }

   /* Give the result modulo mod, if mod=!-1, otherwise give the full result.*/
   if(mod != -1)
   {
      partitions[n] = res % mod;

      return res % mod;
   }
   else
   {
      partitions[n] = res;

      return res;
   }
}

/* Function implementing Dijkstra's algorithm for a mxn matrix, where the matrix represents
 * a graph in which each value can be connected to two, three or four adjacent values.
 * The parameters are the graph matrix, a matrix storing the distances, the size m and n of
 * the matrix, two flags, up and back, that determines if the path can also go up and/or back
 * instead of only down and forward, and the starting row.*/
int dijkstra(int **matrix, int **distances, int m, int n, int up, int back, int start)
{
   int i, j, min_i, min_j, min;
   int **visited;

   if((visited = (int **)malloc(m*sizeof(int *))) == NULL)
   {
      return -1;
   }

   for(i = 0; i < m; i++)
   {
      if((visited[i] = (int *)calloc(n, sizeof(int))) == NULL)
      {
         return -1;
      }
   }

   /* Set the current distances to the maximum value.*/
   for(i = 0; i < m; i++)
   {
      for(j = 0; j < n; j++)
      {
         distances[i][j] = INT_MAX;
      }
   }

   /* Set the distance of the starting node to its value.*/
   i = start;
   j = 0;
   distances[i][j] = matrix[i][j];

   do
   {
      /* Visit the first node, and update the distance of its 2, 3 or 4
       * adjacent nodes.*/
      visited[i][j] = 1;

      if(i < m - 1 && distances[i][j] + matrix[i+1][j] < distances[i+1][j])
      {
         distances[i+1][j] = distances[i][j] + matrix[i+1][j];
      }

      if(up)
      {
         if(i > 0 && distances[i][j] + matrix[i-1][j] < distances[i-1][j])
         {
            distances[i-1][j] = distances[i][j] + matrix[i-1][j];
         }
      }

      if(j < n -1 && distances[i][j] + matrix[i][j+1] < distances[i][j+1])
      {
         distances[i][j+1] = distances[i][j] + matrix[i][j+1];
      }

      if(back)
      {
         if(j > 0 && distances[i][j] + matrix[i][j-1] < distances[i][j-1])
         {
            distances[i][j-1] = distances[i][j] + matrix[i][j-1];

         }
      }

      min = INT_MAX;

      /* Find the non visited node with the current minimum distance.*/
      for(i = 0; i < m; i++)
      {
         for(j = 0; j < n; j++)
         {
            if(!visited[i][j] && distances[i][j] <= min)
            {
               min = distances[i][j];
               min_i = i;
               min_j = j;
            }
         }
      }

      i = min_i;
      j = min_j;
   /* Repeat until all nodes have been visited.*/
   }while(i != m - 1 || j != n - 1);

   return 1;
}
