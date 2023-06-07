# By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles.
# Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.

import sys

from projecteuler import timing


@timing
def p085():
    N = 2000000
    min_diff = sys.maxsize

    for i in range(1, 100):
        for j in range(1, i + 1):
            # In a 2x3 grid, we can take rectangles of height 2 in 3 ways (two rectangles of heigh
            # one and one of height 2). For the width, we can take 6 rectangles (3 of width 1,
            # 2 of width 2 and 1 of width 3). The total is 6x3=18 rectangles.
            # Extending to m x n, we can take (m+m-1+m-2+...+1)x(n+n-1+n-2+...+1)=
            # m(m + 1) / 2 * n(n + 1) / 2 = m(m + 1) * n(n + 1) / 4 rectangles
            n = (i * (i + 1) * j * (j + 1)) / 4
            diff = abs(N - n)

            if diff < min_diff:
                min_diff = diff
                area = i * j

    print('Project Euler, Problem 85')
    print(f'Answer: {area}')


if __name__ == '__main__':
    p085()
