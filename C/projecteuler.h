#ifndef _PROJECTEULER_INCLUDED
#define _PROJECTEULER_INCLUDED

int is_prime(long int);
long int lcmm(long int *values, int n);
long int lcm(long int a, long int b);
long int gcd(long int a, long int b);
int *sieve(int n);
int count_divisors(int n);
void quick_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv));

#endif
