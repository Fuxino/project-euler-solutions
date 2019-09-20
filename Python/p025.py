#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    fib1 = 1
    fib2 = 1
    fibn = fib1 + fib2

    i = 3

    while len(str(fibn)) < 1000:
        fib1 = fib2
        fib2 = fibn
        fibn = fib1 + fib2
        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 25')
    print('Answer: {}'.format(i))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
