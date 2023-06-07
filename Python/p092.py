# A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.
#
# For example,
#
# 44 → 32 → 13 → 10 → 1 → 1
# 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89
#
# Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that
# EVERY starting number will eventually arrive at 1 or 89.
#
# How many starting numbers below ten million will arrive at 89?

from numpy import zeros

from projecteuler import timing


N = 10000000
chains = zeros(N)


def chain(n):
    tmp = 0

    if n == 1:
        return 1

    if n == 89:
        return 89

    if chains[n] != 0:
        return chains[n]

    while n > 0:
        digit = n % 10
        tmp += digit ** 2
        n //= 10

    return chain(tmp)


@timing
def p092():
    count = 0

    for i in range(1, N):
        chains[i] = chain(i)

        if chains[i] == 89:
            count += 1

    print('Project Euler, Problem 92')
    print(f'Answer: {count}')


if __name__ == '__main__':
    p092()
