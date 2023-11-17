from collections import defaultdict
from re import L

t = int(input())
for _ in range(t):
    n = int(input())
    m = defaultdict(list)
    s = 0
    a = list(map(int, input().split()))
    cur = a[0]
    for i in range(1, n):
        if cur != a[i]:
            m[cur].append((s, i - 1))
            cur = a[i]
            s = i
    m[a[-1]].append((s, n - 1))
    mS = 0
    mE = 0
    mG = a[0]
    mP = 1
    for key, l in m.items():
        p = 0
        cS = -1
        lE = -1
        for s, e in l:
            if p > mP:
                mS = cS
                mE = lE
                mG = key
                mP = p
            if lE == -1:
                cS = s
                lE = e
                p = e - s + 1
                continue
            if p - (s - lE - 1) < 1:
                cS = s
                lE = e
                p = e - s + 1
                continue
            p -= s - lE - 1
            lE = e
            p += e - s + 1
        if p > mP:
            mS = cS
            mE = lE
            mG = key
            mP = p
    print(mG, mS + 1, mE + 1)