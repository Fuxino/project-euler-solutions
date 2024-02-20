/* Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are
 * relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 *
 * n	Relatively Prime	φ(n)	n/φ(n)
 * 2	1	                1	   2
 * 3	1,2	                2 	   1.5
 * 4	1,3	                2	   2
 * 5	1,2,3,4	            4	   1.25
 * 6	1,5	                2	   3
 * 7	1,2,3,4,5,6	        6	   1.1666...
 * 8	1,3,5,7	            4	   2
 * 9	1,2,4,5,7,8	        6	   1.5
 * 10	1,3,7,9	            4	   2.5
 *
 * It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
 *
 * Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projecteuler.h"

#define N 1000000

int main(int argc, char **argv)
{
    int i, res = 1;
	double elapsed;
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    i = 1;

    /* Using Euler's formula, phi(n)=n*prod(1-1/p), where p are the distinct
     * primes that divide n. So n/phi(n)=1/prod(1-1/p). To find the maximum
     * value of this function, the denominator must be minimized. This happens
     * when n has the most distinct small prime factor, i.e. to find the solution
     * we need to multiply the smallest consecutive primes until the result is
     * larger than 1000000.*/
    while(res < N)
    {
        i++;
        
        if(is_prime(i))
        {
            res *= i;
        }
    }

    /* We need the previous value, because we want i<1000000.*/
    res /= i;

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec-start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

    printf("Project Euler, Problem 69\n");
	printf("Answer: %d\n", res);

    printf("Elapsed time: %.9lf seconds\n", elapsed);

	return 0;
}
