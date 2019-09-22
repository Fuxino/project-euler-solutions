#!/usr/bin/python3

from timeit import default_timer

def main():
    start = default_timer()

    try:
        fp = open('names.txt', 'r')
    except:
        print('Error while opening file {}'.format('names.txt'))
        exit(1)

    names = list(fp.readline().replace('"', '').split(','))
    names.sort()

    sum_ = 0
    i = 1

    for name in names:
        l = len(name)
        score = 0
        for j in range(l):
            score = score + ord(name[j]) - ord('A') + 1
        score = score * i
        sum_ = sum_ + score
        i = i + 1

    end = default_timer()

    print('Project Euler, Problem 22')
    print('Answer: {}'.format(sum_))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
