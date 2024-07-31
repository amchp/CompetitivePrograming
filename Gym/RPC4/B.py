from math import atan, pi

n = int(input())
a = []

for _ in range(n):
    x, y = map(int, input().split())
    a.append((x, y))

m = (a[0][0], a[0][1])
slope = 0

for x, y in a:
    if m[1] < y:
        curSlope = min((y - m[1]) / (x - m[0]), (y - a[0][1]) / (x - a[0][0]))
        slope = max(slope, curSlope)
        m = (x, y)
m = (a[-1][0], a[-1][1])

for i in range(n):
    x, y = a[n - i - 1]
    if m[1] < y:
        curSlope = min((y - m[1]) / abs(m[0] - x), (y - a[-1][1]) / abs(a[-1][0] - x))
        slope = max(slope, curSlope)
        m = (x, y)
print(f"{(atan(slope) * (180/pi)):0,.20f}")