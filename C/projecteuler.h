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
int *build_sqrt_cont_fraction(int i, int *period, int l);
int pell_eq(int i, mpz_t x);
int is_semiprime(int n, int *p, int *q, int *primes);
int phi_semiprime(int n, int p, int q);
int phi(int n, int *primes);
long int partition_fn(int n, long int *partitions);

#endif
