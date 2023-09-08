import gmpy2
from gmpy2 import mpz, random_state


def pollards_rho(n):
    state = gmpy2.random_state()
    x = gmpy2.mpz_random(state, n)
    y = x
    c = gmpy2.mpz_random(state, n)
    d = mpz(1)

    while d == 1:
        x = (x * x + c) % n
        y = (y * y + c) % n
        y = (y * y + c) % n
        d = gmpy2.gcd(gmpy2.sub(x, y), n)

    return d


def factorize_large_number(n):
    factors = []
    while n > 1:
        factor = pollards_rho(n)
        while n % factor == 0:
            factors.append(factor)
            n //= factor
    return factors


# Đọc số lượng bộ test
T = int(input())
for _ in range(T):
    N = mpz(int(input()))
    factors = factorize_large_number(N)
    factors.sort()

    factors_output = []
    for factor in factors:
        count = 0
        while N % factor == 0:
            N //= factor
            count += 1
        factors_output.append((factor, count))

    for factor, count in factors_output:
        print(factor, count)
    print()
