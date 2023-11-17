from math import log2, pow

t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    if n&x != x:
        print(-1)
        continue
    
    if x == 0:
        if n == 0:
            print(0)
            continue
        print(int(pow(2, int(log2(n)) + 1)))
        continue
    print(n + (n^x))