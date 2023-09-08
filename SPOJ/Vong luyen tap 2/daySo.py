MOD = 998244353


def solve(n, a):
    a.sort()
    ans = 0

    for i in range(n):
        ans += a[2 * n - i - 1] - a[i]
        ans %= MOD

    return ans


# Đọc dữ liệu đầu vào
n = int(input())
a = list(map(int, input().split()))

# Gọi hàm giải bài toán và in ra kết quả
result = solve(n, a)
print(result)
