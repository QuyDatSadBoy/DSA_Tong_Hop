
n = int(input())
a = [int(input()) for _ in range(n)]

max_value = a[0]
for i in range(1, n):
    if a[i] <= a[i - 1]:
        max_value += 1
    max_value = max(max_value, a[i])

print(max_value)
