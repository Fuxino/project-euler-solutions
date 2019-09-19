#!/usr/bin/python3

from timeit import default_timer

def main():

    start = default_timer()

    fib1 = 1
    fib2 = 2
    fibn = fib1 + fib2
    sum_ = 2

    while fibn < 4000000:
        if fibn % 2 == 0:
            sum_ = sum_ + fibn

        fib1 = fib2
        fib2 = fibn
        fibn = fib1 + fib2

    end = default_timer()

    print('Project Euler, Problem 2')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
