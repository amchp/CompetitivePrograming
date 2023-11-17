from math import log2

n = int(input())

a = list(map(float, input().split()))

ans = 0

for num in a:
    ans += num ** 3

print(ans**(1/3))

print(1e6 * log2(1e6)/ 3e8)