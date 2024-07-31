m, n, p = map(int, input().split())
    
dp = [[-1 for __ in range(n + 1)] for _ in range(p)]
    
def sol(i, choosen):
    if i == p:
        return choosen == 0
    if choosen == 0:
        return 0
    if dp[i][choosen] != -1:
        return dp[i][choosen]
    dp[i][choosen] = sol(i + 1, choosen - 1) * (2*choosen)
    dp[i][choosen] += sol(i + 1, choosen) * (m - i - 2*choosen)
    return dp[i][choosen]
    
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)
    
    
num = sol(0, n) 
    
den = 1
    
for i in range(p):
    den *= m - i
    
v = gcd(num, den)
num = int(num / v)
den = int(den / v)
    
print(f'{num}/{den}')
    