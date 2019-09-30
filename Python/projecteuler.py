#!/usr/bin/python3

from math import sqrt, floor, ceil, gcd

from numpy import zeros

def is_prime(num):
    if num < 4:
#       If num is 2 or 3 then it's prime.
        return num == 2 or num == 3

#   If num is divisible by 2 or 3 then it's not prime.
    if num % 2 == 0 or num % 3 == 0:
        return False
#   Any number can have only one prime factor greater than its
#   square root. If we reach the square root and we haven't found
#   any smaller prime factors, then the number is prime.
    limit = floor(sqrt(num)) + 1

#   Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
#   If I check all those value no prime factors of the number
#   will be missed. If a factor is found, the number is not prime
#   and the function returns 0.
    for i in range(5, limit, 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False

#   If no factor is found up to the square root of num, num is prime.
    return True

def is_palindrome(num, base):
    reverse = 0

    tmp = num

#   Start with reverse=0, get the rightmost digit of the number using
#   modulo operation (num modulo base), add it to reverse. Remove the
#   rightmost digit from num dividing num by the base, shift the reverse left
#   multiplying by the base, repeat until all digits have been inserted
#   in reverse order.
    while tmp > 0:
        reverse = reverse * base
        reverse = reverse + tmp % base
        tmp = tmp // base

#   If the reversed number is equal to the original one, then it's palindrome.
    if num == reverse:
        return True

    return False
# Least common multiple algorithm using the greatest common divisor.
def lcm(a, b):
    return a * b // gcd(a, b)

# Recursive function to calculate the least common multiple of more than 2 numbers.
def lcmm(values, n):
#   If there are only two numbers, use the lcm function to calculate the lcm.
    if n == 2:
        return lcm(values[0], values[1])

    value = values[0]

#   Recursively calculate lcm(a, b, c, ..., n) = lcm(a, lcm(b, c, ..., n)).
    return lcm(value, lcmm(values[1:], n-1))

# Function implementing the Sieve or Eratosthenes to generate
# primes up to a certain number.
def sieve(n):
    primes = [1] * n

#   0 and 1 are not prime, 2 and 3 are prime.
    primes[0] = 0
    primes[1] = 0
#    primes[2] = 1
#    primes[3] = 1

#   Cross out (set to 0) all even numbers and set the odd numbers to 1 (possible prime).
    for i in range(4, n -1, 2):
        primes[i] = 0
#        primes[i+1] = 1

#   If i is prime, all multiples of i smaller than i*i have already been crossed out.
#   if i=sqrt(n), all multiples of i up to n (the target) have been crossed out. So
#   there is no need check i>sqrt(n).
    limit = floor(sqrt(n))

    for i in range(3, limit, 2):
#       Find the next number not crossed out, which is prime.
        if primes[i] == 1:
#           Cross out all multiples of i, starting with i*i because any smaller multiple
#           of i has a smaller prime factor and has already been crossed out. Also, since
#           i is odd, i*i+i is even and has already been crossed out, so multiples are
#           crossed out with steps of 2*i.
            for j in range(i * i, n, 2 * i):
                primes[j] = 0

    return primes

def count_divisors(n):
    count = 0
#   For every divisor below the square root of n, there is a corresponding one
#   above the square root, so it's sufficient to check up to the square root of n
#   and count every divisor twice. If n is a perfect square, the last divisor is
#   wrongly counted twice and must be corrected.
    limit = floor(sqrt(n))

    for i in range(1, limit):
        if n % i == 0:
            count = count + 2

    if n == limit * limit:
        count = count - 1

    return count

def find_max_path(triang, n):
#   Start from the second to last row and go up.
    for i in range(n-2, -1, -1):
#       For each element in the row, check the two adjacent elements
#       in the row below and sum the larger one to it. At the end,
#       the element at the top will contain the value of the maximum path.
        for j in range(0, i+1):
            if triang[i+1][j] > triang[i+1][j+1]:
                triang[i][j] = triang[i][j] + triang[i+1][j]
            else:
                triang[i][j] = triang[i][j] + triang[i+1][j+1]

    return triang[0][0]

def sum_of_divisors(n):
#   For each divisor of n smaller than the square root of n,
#   there is another one larger than the square root. If i is
#   a divisor of n, so is n/i. Checking divisors i up to square
#   root of n and adding both i and n/i is sufficient to sum
#   all divisors.
    limit = floor(sqrt(n)) + 1

    sum_ = 1

    for i in range(2, limit):
        if n % i == 0:
            sum_ = sum_ + i
#           If n is a perfect square, i=limit is a divisor and
#           has to be counted only once.
            if n != i * i:
                sum_ = sum_ + n // i

    return sum_

def is_pandigital(value, n):
    i = 0
    digits = [0] * (n + 1)

    while i < n and value > 0:
        digit = value % 10
        if digit > n:
            return False
        digits[digit] = digits[digit] + 1
        value = value // 10
        i = i + 1

    if i < n or value > 0:
        return False

    if digits[0] != 0:
        return False

    for i in range(1, n+1):
        if digits[i] != 1:
            return False
        i = i + 1

    return True

def is_pentagonal(n):
#   A number n is pentagonal if p=(sqrt(24n+1)+1)/6 is an integer.
#   In this case, n is the pth pentagonal number.
    i = (sqrt(24*n+1) + 1) / 6

    return i.is_integer()

# Function implementing the iterative algorithm taken from Wikipedia
# to find the continued fraction for sqrt(S). The algorithm is as
# follows:
#
# m_0=0
# d_0=1
# a_0=floor(sqrt(n))
# m_(n+1)=d_n*a_n-m_n
# d_(n+1)=(S-m_(n+1)^2)/d_n
# a_(n+1)=floor((sqrt(S)+m_(n+1))/d_(n+1))=floor((a_0+m_(n+1))/d_(n+1))
# if a_i=2*a_0, the algorithm ends.
def build_sqrt_cont_fraction(i, l):
    mn = 0
    dn = 1
    count = 0

    fraction = [0] * l

    j = 0
    a0 = floor(sqrt(i))
    an = a0
    fraction[j] = an
    j = j + 1

    while True:
        mn1 = dn * an - mn
        dn1 = (i - mn1 * mn1)/ dn
        an1 = floor((a0+mn1)/dn1)
        mn = mn1
        dn = dn1
        an = an1
        count = count + 1
        fraction[j] = an
        j = j + 1

        if an == 2 * a0:
            break

    fraction[j] = -1

    return fraction, count

# Function to solve the Diophantine equation in the form x^2-Dy^2=1
# (Pell equation) using continued fractions.

def pell_eq(d):
#   Find the continued fraction for sqrt(d).
    fraction, period = build_sqrt_cont_fraction(d, 100)

#   Calculate the first convergent of the continued fraction.
    n1 = 0
    n2 = 1
    d1 = 1
    d2 = 0

    j = 0
    n3 = fraction[j] * n2 + n1
    d3 = fraction[j] * d2 + d1
    j = j + 1

#   Check if x=n, y=d solve the equation x^2-Dy^2=1.
    sol = n3 * n3 - d * d3 * d3

    if sol == 1:
        return n3

#   Until a solution is found, calculate the next convergent
#   and check if x=n and y=d solve the equation.
    while True:
        n1 = n2
        n2 = n3
        d1 = d2
        d2 = d3
        n3 = fraction[j] * n2 + n1
        d3 = fraction[j] * d2 + d1

        sol = n3 * n3 - d * d3 * d3

        if sol == 1:
            return n3

        j = j + 1

        if fraction[j] == -1:
            j = 1

# Function to check if a number is semiprime. Parameters include
# pointers to p and q to return the factors values and a list of
# primes.
def is_semiprime(n, primes):
#   If n is prime, it's not semiprime.
    if primes[n] == 1:
        return False, -1, -1

#   Check if n is semiprime and one of the factors is 2.
    if n % 2 == 0:
        if primes[n//2] == 1:
            p = 2
            q = n // 2
            return True, p, q
        else:
            return False, -1, -1
#   Check if n is semiprime and one of the factors is 3.
    elif n % 3 == 0:
        if primes[n//3] == 1:
            p = 3
            q = n // 3
            return True, p, q
        else:
            return False, -1, -1

#   Any number can have only one prime factor greater than its
#   square root, so we can stop checking at this point.
    limit = floor(sqrt(n)) + 1

#   Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
#   If I check all those value no prime factors of the number 
#   will be missed. For each of these possible primes, check if 
#   they are prime, then if the number is semiprime with using
#   that factor.
    for i in range(5, limit, 6):
        if primes[i] == 1 and n % i == 0:
            if primes[n//i] == 1:
                p = i
                q = n // i
                return True, p, q
            else:
                return False, -1, -1
        elif primes[i+2] == 1 and n % (i + 2) == 0:
            if primes[n//(i+2)] == 1:
                p = i + 2
                q = n // (i + 2)
                return True, p, q
            else:
                return False, -1, -1

    return False, -1, -1

# If n=pq is semiprime, phi(n)=(p-1)(q-1)=pq-p-q+1=n-(p+4)+1
# if p!=q. If p=q (n is a square), phi(n)=n-p.
def phi_semiprime(n, p, q):
    if p == q:
        return n - p
    else:
        return n - (p + q) + 1

def phi(n, primes):
#   If n is primes, phi(n)=n-1.
    if primes[n] == 1:
        return n - 1

#   If n is semiprime, use above function.
    semi_p, p, q = is_semiprime(n, primes)

    if semi_p:
        return phi_semiprime(n, p, q)

    ph = n

#   If 2 is a factor of n, multiply the current ph (which now is n)
#   by 1-1/2, then divide all factors 2.
    if n % 2 == 0:
        ph = ph * (1 - 1 / 2)

        while True:
            n = n // 2

            if n % 2 != 0:
                break

#   If 3 is a factor of n, multiply the current ph by 1-1/3,
#   then divide all factors 3.
    if n % 3 == 0:
        ph = ph * (1 - 1 / 3)

        while True:
            n = n // 3

            if n % 3 != 0:
                break

#   Any number can have only one prime factor greater than its
#   square root, so we can stop checking at this point and deal
#   with the only factor larger than sqrt(n), if present, at the end
    limit = floor(sqrt(n)) + 1

#   Every prime other than 2 and 3 is in the form 6k+1 or 6k-1.
#   If I check all those value no prime factors of the number 
#   will be missed. For each of these possible primes, check if 
#   they are prime, then check if the number divides n, in which
#   case update the current ph.
    for i in range(5, limit, 6):
        if primes[i]:
            if n % i == 0:
                ph = ph * (1 - 1 / i)

                while True:
                    n = n // i

                    if n % i != 0:
                        break
        if primes[i+2]:
            if n % (i + 2) == 0:
                ph = ph * (1 - 1 / (i + 2))

                while True:
                    n = n // (i + 2)

                    if n % (i + 2) != 0:
                        break

#   After dividing all prime factors smaller than sqrt(n), n is either 1
#   or is equal to the only prime factor greater than sqrt(n). In this
#   second case, we need to update ph with the last prime factor.
    if n > 1:
        ph = ph * (1 - 1 / n)

    return ph

# Function implementing the partition function.
def partition_fn(n, partitions, mod=-1):
#   The partition function for negative numbers is 0 by definition.
    if n < 0:
        return 0

#   The partition function for zero is 1 by definition.
    if n == 0:
        partitions[n] = 1
        return 1

#   If the partition for the current n has already been calculated, return the value.
    if partitions[n] != 0:
        return partitions[n]

    res = 0
    k = -ceil((sqrt(24*n+1)-1)//6)
    limit = floor((sqrt(24*n+1)+1)//6)

    while k <= limit:
        if k != 0:
            res = res + pow(-1, k+1) * partition_fn(n-k*(3*k-1)//2, partitions)
        k = k + 1

#   Give the result modulo mod, if mod!=-1, otherwise give the full result.
    if mod != -1:
        partitions[n] = res % mod

        return res % mod
    else:
        partitions[n] = int(res)

        return int(res)

#
def dijkstra(matrix, distances, m, n, up=False, back=False, start=0):
    visited = zeros((m, n), int)

    for i in range(m):
        for j in range(n):
            distances[i][j] = 2 ** 32

    i = start
    j = 0

    distances[i][j] = matrix[i][j]

    while True:
        visited[i][j] = 1

        if i < m - 1 and distances[i][j] + matrix[i+1][j] < distances[i+1][j]:
            distances[i+1][j] = distances[i][j] + matrix[i+1][j]

        if up:
            if i > 0 and distances[i][j] + matrix[i-1][j] < distances[i-1][j]:
                distances[i-1][j] = distances[i][j] + matrix[i-1][j]

        if j < n - 1 and distances[i][j] + matrix[i][j+1] < distances[i][j+1]:
            distances[i][j+1] = distances[i][j] + matrix[i][j+1]

        if back:
            if j > 0 and distances[i][j] + matrix[i][j-1] < distances[i][j-1]:
                distances[i][j-1] = distances[i][j] + matrix[i][j-1]

        min_ = 999999999

        for i in range(m):
            for j in range(n):
                if not visited[i][j] and distances[i][j] <= min_:
                    min_ = distances[i][j]
                    min_i = i
                    min_j = j

        i = min_i
        j = min_j

        if i == m - 1 and j == n - 1:
            break
