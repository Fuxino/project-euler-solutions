#ifndef _PROJECTEULER_INCLUDED
#define _PROJECTEULER_INCLUDED

#include <gmp.h>

int is_prime(long int);
int is_palindrome(int num, int base);
int is_palindrome_mpz(mpz_t n, int base);
long int gcd(long int a, long int b);
long int lcm(long int a, long int b);
long int lcmm(long int *values, int n);
int *sieve(int n);
int count_divisors(int n);
int find_max_path(int **triang, int n);
int sum_of_divisors(int n);
void swap(void **vet, int i, int j);
void insertion_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv));
void quick_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv));
int next_permutation(void **perm, int n, int (*cmp)(void *a, void *b));
int is_pandigital(int value, int n);
int is_pentagonal(long int n);
int period_cf(int n);

#endif
