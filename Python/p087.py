# The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact,
# there are exactly four numbers below fifty that can be expressed in such a way:
#
# 28 = 22 + 23 + 24
# 33 = 32 + 23 + 24
# 49 = 52 + 23 + 24
# 47 = 22 + 33 + 24
#
# How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?

from numpy import zeros

from projecteuler import sieve, timing


@timing
def p087():
    N = 50000000
    SQRT_N = 7071
    RAD3_N = 368
    RAD4_N = 84

    primes = sieve(SQRT_N + 1)
    numbers = zeros(N)
    count = 0

    for i in range(2, SQRT_N + 1):
        if primes[i]:
            for j in range(2, RAD3_N + 1):
                if primes[j]:
                    for k in range(2, RAD4_N + 1):
                        if primes[k]:
                            n = i ** 2 + j ** 3 + k ** 4

                            if n < N and numbers[n] == 0:
                                count += 1
                                numbers[n] = 1

    print('Project Euler, Problem 87')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p087()
