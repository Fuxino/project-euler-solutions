#!/usr/bin/python3

from timeit import default_timer
def main():
    start = default_timer()

    sum_squares = 0
    square_sum = 0

    for i in range(1, 101):
        sum_squares = sum_squares + i * i
        square_sum = square_sum + i

    square_sum = square_sum * square_sum

    end = default_timer()

    print('Project Euler, Problem 6')
    print('Answer: {}'.format(square_sum - sum_squares))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
