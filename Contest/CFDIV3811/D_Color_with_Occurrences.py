q = int(input())
while q:
    t = input()
    n = int(input())
    s = [""]*n
    for i in range(n):
        s[i] = input()
    c = [[] for _ in range(len(t))]
    for i in range(n):
        res = [j for j in range(len(t)) if t.startswith(s[i], j)]
        for x in res:
            c[x].append((x + len(s[i]), i))
    for a in c:
        a.sort(reverse=True)
    p = True
    start = 0
    end = 0
    ans = []
    while end < len(t):
        mI = start
        mD = end
        for i in range(start, end + 1):
            if len(c[i]) == 0:
                continue
            if mD < c[i][0][0]:
                mI = i
                mD = c[i][0][0]
        if mD == end:
            p = False
            break
        ans.append((c[mI][0][1] + 1, mI + 1))
        start = mI
        end = mD
    if p:
        print(len(ans))
        for x, y in ans:
            print(x, y)
    else:
        print(-1)
    q -= 1