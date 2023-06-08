# Both 169 and 961 are the square of a prime. 169 is the reverse of 961.
#
# We call a number a reversible prime square if:
#
# 1. It is not a palindrome, and
# 2. It is the square of a prime, and
# 3. Its reverse is also the square of a prime.
#
# 169 and 961 are not palindromes, so both are reversible prime squares.
#
# Find the sum of the first 50 reversible prime squares.

from math import sqrt

from projecteuler import is_palindrome, sieve, timing


@timing
def p808():
    n = 1
    primes = sieve(50000000)
    reversible_prime_squares = []

    for n, p in enumerate(primes):
        if not p:
            continue

        n_squared = n * n

        if not is_palindrome(n_squared):
            n_reverse = int(str(n_squared)[::-1])
            n_reverse_sqrt = sqrt(n_reverse)

            if n_reverse_sqrt.is_integer() and primes[int(n_reverse_sqrt)]:
                reversible_prime_squares.append(n_squared)

        if len(reversible_prime_squares) == 50:
            break

    res = sum(reversible_prime_squares)

    print('Project Euler, Problem 808')
    print(f'Answer: {res}')


if __name__ == '__main__':
    p808()
