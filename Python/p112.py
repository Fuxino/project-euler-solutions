# Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
#
# Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
#
# We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
#
# Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy.
# In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
#
# Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
#
# Find the least number for which the proportion of bouncy numbers is exactly 99%.

from projecteuler import timing


def is_bouncy(n):
    i = 0

    n = str(n)
    l = len(n)

    while i < l - 1 and n[i] == n[i + 1]:
        i += 1

    if i == l - 1:
        return False

    if n[i] < n[i + 1]:
        for i in range(i, l - 1):
            if n[i] > n[i + 1]:
                return True

    if n[i] > n[i + 1]:
        for i in range(i, l - 1):
            if n[i] < n[i + 1]:
                return True

    return False


@timing
def p112():
    i = 100
    n_bouncy = 0
    ratio = 0.0

    while True:
        if is_bouncy(i):
            n_bouncy += 1

        ratio = n_bouncy / i

        if ratio == 0.99:
            break

        i += 1

    print('Project Euler, Problem 112')
    print(f'Answer: {i}')


if __name__ == '__main__':
    p112()
