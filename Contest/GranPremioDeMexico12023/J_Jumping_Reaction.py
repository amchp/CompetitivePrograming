n, q = map(int, input().split())
def 

a = list(map(int, input().split()))
MOD = (int(1e9) + 7)
pfx = [0]*(n + 1)
pfx2 = [0]*(n + 1)
for i in range(n):
    pfx[i + 1] = (pfx[i] + a[i]) % MOD
    pfx2[i + 1] = (pfx2[i] + (a[i] * a[i]) % MOD) % MOD
    
for _ in range(q):
    l, r = map(int, input().split())
    if l == r:
        print(a[l - 1])
        continue
    l -= 1
    sAns = (pfx[r] - pfx[l] + MOD) % MOD
    tAns = int((((sAns * sAns) % MOD - (pfx2[r] - pfx2[l] + MOD) + MOD) % MOD))
    if tAns % 2:
        tAns =
    print(ans % MOD)