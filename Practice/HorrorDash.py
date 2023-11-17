t = int(input())
for u in range(t):
    l = [int(n) for n in input().split()]
    m = 0
    for e in l:
        m = max(m, e)
    print("Case " + str(u+1) +  ": " + str(m))