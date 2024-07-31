from math import pi, asin

n, e = map(int, input().split())
a = list(map(int, input().split()))
ans = 0
for num in a:
    print()
    if not(-1 <= e / (2*num) and e / (2*num) <= 1):
        ans += 1
        continue
    teta = asin(e/(2*num))
    teta = pi / teta
    ans += int(teta)
print(ans)