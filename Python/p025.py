#!/usr/bin/python3

# The Fibonacci sequence is defined by the recurrence relation:
#
# Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
# Hence the first 12 terms will be:
# F1 = 1
# F2 = 1
# F3 = 2
# F4 = 3
# F5 = 5
# F6 = 8
# F7 = 13
# F8 = 21
# F9 = 34
# F10 = 55
# F11 = 89
# F12 = 144
#
# The 12th term, F12, is the first term to contain three digits.
#
# What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

from timeit import default_timer

def main():
    start = default_timer()

    fib1 = 1
    fib2 = 1
    fibn = fib1 + fib2

    i = 3

#   Calculate the Fibonacci numbers until one with 1000 digits is found.
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
