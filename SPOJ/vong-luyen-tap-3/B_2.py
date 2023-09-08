def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def count_special_pairs(N):
    def count_primes(limit):
        primes = [True] * (limit + 1)
        primes[0], primes[1] = False, False
        p = 2
        while p * p <= limit:
            if primes[p]:
                for i in range(p * p, limit + 1, p):
                    primes[i] = False
            p += 1
        return primes

    count = 0
    primes = count_primes(N)
    for x in range(2, N + 1):
        if primes[sum(map(int, str(x)))]:
            y = N - x
            if primes[sum(map(int, str(y)))]:
                count += 1
    return count


N = int(input())
result = count_special_pairs(N)
print(result)
