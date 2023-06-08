# The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1;
# it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.
#
# However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.
#
# Find the last ten digits of this prime number.

from projecteuler import timing


@timing
def p097():
    b = 2
    e = 7830457
    e_first = 0
    m = 10000000000
    c = 1

    while e_first < e:
        e_first += 1
        c = (b * c) % m

    result = (c*28433 + 1) % m

    print('Project Euler, Problem 97')
    print(f'Answer: {result}')


if __name__ == '__main__':
    p097()
