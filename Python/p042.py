#!/usr/bin/python3

from timeit import default_timer

def is_triang(n):
    i = 1
    j = 1

    while j <= n:
        if n == j:
            return True
        i = i + 1
        j = j + i

    return False

def main():
    start = default_timer()

    try:
        fp = open('words.txt', 'r')
    except:
        print('Error while opening file {}'.format('words.txt'))
        exit(1)

    words = list(fp.readline().replace('"', '').split(','))

    fp.close()

    count = 0

    for word in words:
        value = 0
        l = len(word)

        for j in range(l):
            value = value + ord(word[j]) - ord('A') + 1

        if is_triang(value):
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 42')
    print('Answer: {}'.format(count))

    print('Elapsed time: {:.9f} seconds'.format(end - start))

if __name__ == '__main__':
    main()
