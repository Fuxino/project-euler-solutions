#!/usr/bin/env python3

# Using p022_names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order.
# Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
#
# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
# So, COLIN would obtain a score of 938 × 53 = 49714.
#
# What is the total of all the name scores in the file?

import sys
from timeit import default_timer


def main():
    start = default_timer()

    try:
        with open('p022_names.txt', 'r', encoding='utf-8') as fp:
            names = list(fp.readline().replace('"', '').split(','))
    except FileNotFoundError:
        print('Error while opening file p022_names.txt')
        sys.exit(1)

    names.sort()

    sum_ = 0
    i = 1

#   Calculate the score of each name an multiply by its position.
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
    print(f'Answer: {sum_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
