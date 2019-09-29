/* The square root of 2 can be written as an infinite continued fraction.
 *
 * √2=1+1/(2+1/(2+1/(2+1/(2+...
 *
 * The infinite continued fraction can be written, √2=[1;(2)], (2) indicates that 2 repeats ad infinitum. In a similar way, √23=[4;(1,3,1,8)].
 * It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
 * Let us consider the convergents for √22.
 *
 * 1+1/2=3/2
 * 1+1/(2+1/2)=7/5
 * 1+1/(2+1/(2+1/2))=17/12
 * 1+1/(2+1/(2+1/(2+1/2)))=41/29
 *
 * Hence the sequence of the first ten convergents for √2 are:
 *
 * 1,3/2,7/5,17/12,41/29,99/70,239/169,577/408,1393/985,3363/2378,...
 *
 * What is most surprising is that the important mathematical constant,
 *
 * e=[2;1,2,1,1,4,1,1,6,1,...,1,2k,1,...].
 *
 * The first ten terms in the sequence of convergents for e are:
 *
 * 2,3,8/3,11/4,19/7,87/32,106/39,193/71,1264/465,1457/536,...
 *
 * The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
 *
 * Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char **argv)
{
   int i, ai[3] = {1, 2, 1}, count = 4, sum = 0;
   mpz_t n0, n1, n2;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   mpz_init_set_ui(n0, 3);
   mpz_init_set_ui(n1, 8);
   mpz_init_set_ui(n2, 11);

   /* For a continued fractions [a_0; a_1, a_2, ...], the numerator of the 
    * next convergent N_n=a_n*N_(n-1)+N_(n-2). The first three values for e are
    * 3, 8 and 11, the next ones are easily calculated, considering that a_n
    * follows a simple pattern: 
    * a_1=1, a_2=2, a_3=1
    * a_4=1, a_5=4, a_6=1
    * a_7=1, a_8=6, a_9=1
    * and so on.*/
   while(count < 100)
   {
      ai[1] += 2;

      for(i = 0; i < 3 && count < 100; i++)
      {
         mpz_set(n0, n1);
         mpz_set(n1, n2);
         mpz_mul_ui(n2, n1, ai[i]);
         mpz_add(n2, n2, n0);
         count++;
      }
   }

   /* Sum the digits.*/
   while(mpz_cmp_ui(n2, 0))
   {
      sum += mpz_tdiv_q_ui(n2, n2, 10);
   }

   mpz_clears(n0, n1, n2, NULL);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 65\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
