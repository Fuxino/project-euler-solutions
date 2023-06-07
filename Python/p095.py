# The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors
# of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.
#
# Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220,
# forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.
#
# Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:
#
# 12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)
#
# Since this chain returns to its starting point, it is called an amicable chain.
#
# Find the smallest member of the longest amicable chain with no element exceeding one million.

from numpy import zeros

from projecteuler import sum_of_divisors, timing


N = 1000000
divisors = zeros(N + 1)


def sociable_chain(i, chain, l, min_):
    chain[l] = i

    if i == 1:
        return -1

    if divisors[i] != 0:
        n = int(divisors[i])
    else:
        n = int(sum_of_divisors(i))

    if n > N:
        return -1

    if n == chain[0]:
        return l + 1

    for j in range(l, 0, -1):
        if n == chain[j]:
            return -1

    if n < min_:
        min_ = n

    return sociable_chain(n, chain, l + 1, min_)


@timing
def p095():
    chain = zeros(N)
    min_ = 0
    l_max = 0

    for i in range(4, N + 1):
        divisors[i] = sum_of_divisors(i)

        if divisors[i] == i:
            continue

        min_tmp = i
        length = sociable_chain(i, chain, 0, min_tmp)

        if length > l_max:
            l_max = length
            min_ = min_tmp

    print('Project Euler, Problem 95')
    print(f'Answer: {min_}')


if __name__ == '__main__':
    p095()
