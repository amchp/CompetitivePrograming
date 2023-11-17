def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def lcm(a, b):
    return (a / gcd(a, b)) * b

def sol():
    n = int(input())
    a = list(map(int, input().split()))
    l = 1
    for i in range(n):
        if gcd(a[i], l) != 1:
            return True
        l = lcm(a[i], l)
    return False

t = int(input())
for _ in range(t):
    if sol():
        print("YES")
    else:
        print("NO")