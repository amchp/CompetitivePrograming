t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    m = int(len(s) / (k + 1))
    r = len(s) % (k + 1)
    ans = float('inf')
    d = 0
    def comb(ind, sum):
        # print(ind)
        global d
        if ind >= n:
            if d != k + 1:
                return
            global ans
            ans = min(ans, sum)
            return
        for i in range(max(ind + m - 1, ind + 1), min(ind + m + 2, n + 1)):
            # print(max(ind + m - 1, ind + 1), min(ind + m + 1, n + 1))
            d += 1
            comb(i, sum + int(s[ind:i]))
            d -= 1
    comb(0, 0)
    print(ans)
    