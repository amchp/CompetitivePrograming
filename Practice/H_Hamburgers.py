s = input()
nB, nS, nC = 0, 0, 0
for c in s:
    nB += c == 'B'
    nS += c == 'S'
    nC += c == 'C'
cB, cS, cC = map(int, input().split())
pB, pS, pC = map(int, input().split())
rubles = int(input())

def works(m):
    dB = max(0, nB * m - cB)
    dS = max(0, nS * m - cS)
    dC = max(0, nC * m - cC)
    dR = dB * pB + dS * pS + dC * pC
    return dR <= rubles

l = -1 
r = int(1e18)
while l + 1 < r:
    m = int(l + (r - l) / 2)
    if works(m):
        l = m
    else:
        r = m
print(l)
