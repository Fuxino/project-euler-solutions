#!/usr/bin/python3

from timeit import default_timer

def sum_triangle(triang, n, i, j, sum_):
    global max_

    if i == n:
        if sum_ > max_:
            max_ = sum_
        return max_

    sum_triangle(triang, n, i+1, j, sum_+triang[i][j])
    sum_triangle(triang, n, i+1, j+1, sum_+triang[i][j])

def main():
    global max_

    start = default_timer()

    try:
        fp = open('triang.txt', 'r')
    except:
        print('Error while opening file {}'.format('triang.txt'))
        exit(1)

    triang = list()

    for line in fp:
        triang.append(line.strip('\n').split())

    fp.close()

    for i in range(len(triang)):
        triang[i] = list(map(int, triang[i]))

    max_ = 0
    sum_triangle(triang, 15, 0, 0, 0)

    end = default_timer()

    print('Project Euler, Problem 18')
    print('Answer: {}'.format(max_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
