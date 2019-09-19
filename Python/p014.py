#!/usr/bin/python3 
from numpy import zeros

from timeit import default_timer

collatz_found = zeros(1000000, dtype=int)

def collatz_length(n):
    if n == 1:
        return 1

    if n < 1000000 and collatz_found[n]:
        return collatz_found[n]

    if n % 2 == 0:
        return 1 + collatz_length(n//2)
    else:
        return 1 + collatz_length(3*n+1)

def main():
    start = default_timer()

    max_l = 0
    max_ = 0

    for i in range(1, 1000000):
        count = collatz_length(i)
        collatz_found[i] = count

        if count > max_l:
            max_l = count
            max_ = i

    end = default_timer()

    print('Project Euler, Problem 14')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
