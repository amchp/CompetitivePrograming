t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    mR = 0
    for i in range(n):
        if a[i] != i + 1:
            mR = i + 1
    if mR == 0:
        print
    nAns = 1
    for __ in range(m):
        r, p = map(float, input().split())
        if r >= mR:
            nAns *= 1 - p
    print(1 - nAns)