#!/usr/bin/python

# The square root of 2 can be written as an infinite continued fraction.
#
# √2=1+1/(2+1/(2+1/(2+1/(2+...
#
# The infinite continued fraction can be written, √2=[1;(2)], (2) indicates that 2 repeats ad infinitum. In a similar way, √23=[4;(1,3,1,8)].
# It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
# Let us consider the convergents for √22.
#
# 1+1/2=3/2
# 1+1/(2+1/2)=7/5
# 1+1/(2+1/(2+1/2))=17/12
# 1+1/(2+1/(2+1/(2+1/2)))=41/29
#
# Hence the sequence of the first ten convergents for √2 are:
#
# 1,3/2,7/5,17/12,41/29,99/70,239/169,577/408,1393/985,3363/2378,...
#
# What is most surprising is that the important mathematical constant,
#
# e=[2;1,2,1,1,4,1,1,6,1,...,1,2k,1,...].
#
# The first ten terms in the sequence of convergents for e are:
#
# 2,3,8/3,11/4,19/7,87/32,106/39,193/71,1264/465,1457/536,...
#
# The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
#
# Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

from timeit import default_timer


def main():
    start = default_timer()

    ai = [1, 2, 1]
    count = 4

    n0 = 3
    n1 = 8
    n2 = 11

#   For a continued fractions [a_0; a_1, a_2, ...], the numerator of the
#   next convergent N_n=a_n*N_(n-1)+N_(n-2). The first three values for e are
#   3, 8 and 11, the next ones are easily calculated, considering that a_n
#   follows a simple pattern:
#   a_1=1, a_2=2, a_3=1
#   a_4=1, a_5=4, a_6=1
#   a_7=1, a_8=6, a_9=1
#   and so on.
    while count < 100:
        ai[1] = ai[1] + 2

        for i in range(3):
            n0 = n1
            n1 = n2
            n2 = n1 * ai[i] + n0
            count = count + 1

            if count >= 100:
                break

    sum_ = 0

    while n2 != 0:
        sum_ = sum_ + n2 % 10
        n2 = n2 // 10

    end = default_timer()

    print('Project Euler, Problem 65')
    print(f'Answer: {sum_}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
