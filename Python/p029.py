#!/usr/bin/python3

from numpy import zeros

from timeit import default_timer

def main():
    start = default_timer()

    powers = zeros(9801)

    for i in range(2, 101):
        a = i
        for j in range(2, 101):
            powers[(i-2)*99+j-2] = a ** j

    powers = list(powers)
    powers.sort()
    
    count = 1

    for i in range(1, 9801):
        if powers[i] != powers[i-1]:
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 29')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
