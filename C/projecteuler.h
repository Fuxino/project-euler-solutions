#ifndef _PROJECTEULER_INCLUDED
#define _PROJECTEULER_INCLUDED

int is_prime(long int);
int is_palindrome(int num, int base);
long int gcd(long int a, long int b);
long int lcm(long int a, long int b);
long int lcmm(long int *values, int n);
int *sieve(int n);
int count_divisors(int n);
int find_max_path(int **triang, int n);
int sum_of_divisors(int n);
void insertion_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv));
void quick_sort(void **array, int l, int r, int (*cmp)(void *lv, void *rv));
int is_pandigital(int value, int n);
int is_pentagonal(long int n);

#endif
