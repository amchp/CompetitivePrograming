fact = [1 for _ in range(10)]
for i in range(1, 10):
    fact[i] = fact[i - 1] * i

p, q = map(int, input().split())

def C(n, r):
    return fact[n] // (fact[r]*fact[n - r])

def binpow(b, e):
    ans = 1
    while e:
        if e & 1:
            ans = ans*b
        b *= b
        e //= 2
    return ans

def sm(n, m):
    inner_sm = 0
    for i in range(2, m + 2):
        inner_sm += C(m + 1, i)*sm(n, m + 1 - i)
    return (binpow(n + 1, m + 1) - 1 - inner_sm) // (m + 1)

def f(x, over):
    return q*sm(x, 5) - p*(x + over)

def ternary_search(l, r):
    while(l + 5 < r):
        m1 = l + (r - l) // 3
        m2 = r - (r - l) // 3
        f1 = f(m1, 1)
        f2 = f(m2, 1)
        if f1 > f2:
            l = m1
        else:
            r = m2
    ans = f(l, 1)
    for i in range(l + 1, r + 1):
        ans = min(ans, f(i, 1))
    return ans

l = -1
r = int(1e22 + 100)
x = -ternary_search(l, r)
if(x < 0):
    x = 0
l = 0
r = int(5e18 + 100)
target = int(1e99)
while(l + 1 < r):
    mid = l + (r - l) // 2
    if(x + f(mid, 0) >= target):
        r = mid
    else:
        l = mid
y = r
print(x)
print(y)

