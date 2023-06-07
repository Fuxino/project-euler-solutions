#!/usr/bin/env python3

# A natural number, N, hat can be written as the sum and product of a given set of at least two natural numbers, {a1,a2,...,ak} is called a product sum number: N = a1 + a2 + ... + ak = a1 x a2 x ... ak.
#
# For example, 6 = 1 + 2 + 3 = 1 x 2 x 3
#
# For a given set of size, k, we shall call the smallest N with this property a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2,3,4,5, and 6 are as follows.
#
# k = 2: 4 = 2 x 2 = 2 + 2
# k = 3: 6 = 1 x 2 x 3 = 1 + 2 + 3
# k = 4: 8 = 1 x 1 x 2 x 4 = 1 + 1 + 2 + 4
# k = 5: 8 = 1 x 1 x 2 x 2 x 2 = 1 + 1 + 2 + 2 + 2
# k = 6: 12 = 1 x 1 x 1 x 1 x 2 x 6 = 1 + 1 + 1 + 1 + 2 + 6
#
# Hence,for 2<=k<=6, the sum for all the minimal product-sum numbers is 4 + 6 + 8 + 12 = 30; note that 8 is only counted once in the sum.
#
# In fact, as the complete set of minimal product-sum numbers for 2<=k<=12 is {4,6,8,12,15,16}, the sum is 61.
#
# What is the sum of all the minimal product-sum numbers for 2<=k<=12000?

from math import prod

from projecteuler import sieve, timing


N = 12000
factorizations = {}
product_sums = {}


def factorize(n, factors, start, max_):
    if n == 1:
        factorizations[start].append(sorted(factors))

        return

    for i in range(max_, 1, -1):
        if n % i == 0:
            factors.append(i)
            factorize(n // i, factors, start, i)
            factors.pop()


@timing
def p088():
    primes = sieve(2*N + 1)

    for i in range(2, 2*N + 1):
        if not primes[i]:
            factorizations[i] = []
            factorize(i, [], i, i)

    for _, f in factorizations.items():
        for i in f:
            l = len(i) + (prod(i) - sum(i))

            if l > N:
                continue

            if l not in product_sums:
                product_sums[l] = prod(i)
            elif prod(i) < product_sums[l]:
                product_sums[l] = prod(i)

    min_prod_sums = list(set(list(product_sums.values())))

    res = sum(min_prod_sums)

    print('Project Euler, Problem 88')
    print(f'Answer: {res}')


if __name__ == '__main__':
    p088()
