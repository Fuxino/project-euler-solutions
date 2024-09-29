#!/usr/bin/env python3

# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
#
# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
# The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#
# Evaluate the sum of all the amicable numbers under 10000.


from projecteuler import sum_of_divisors, timing


@timing
def p021() -> None:
    _sum = 0

    for i in range(2, 10000):
        # Calculate the sum of proper divisors with the function
        # implemented in projecteuler.py.
        n = sum_of_divisors(i)

        # If i!=n and the sum of proper divisors of n=i,
        # sum the pair of numbers and add it to the total.
        if i != n and sum_of_divisors(n) == i:
            _sum = _sum + i + n

    _sum = _sum // 2

    print('Project Euler, Problem 21')
    print(f'Answer: {_sum}')


if __name__ == '__main__':
    p021()
