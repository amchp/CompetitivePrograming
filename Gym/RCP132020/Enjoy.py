def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

a, b = map(int, input().split())

g = gcd(a, b)


l = a // g + 1
r = b // g + 1
ans =  (min(l,r) - 2) * 2 + (max(l, r)) * 2
print(ans)