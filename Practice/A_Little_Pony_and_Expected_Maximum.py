m, n = map(int, input().split())
def exp(b, e):
    ans = 1
    while e > 0:
        if e % 2:
            ans = ans*b
        b = b*b
        e //= 2
    return ans

ans = 0
for i in range(m - 1, -1, -1):
    ans += exp(i / m, n)
ans = m - ans
print(ans)