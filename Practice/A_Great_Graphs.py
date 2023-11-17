t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = 0
    prefix = 0
    for i in range(2, n):
        prefix += (a[i] - a[i - 2]) + (a[i] - a[i - 1])*(i - 2)
        ans += prefix
    print(-ans)