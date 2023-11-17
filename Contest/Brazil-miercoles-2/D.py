from math import atan, pi
n = int(input())
rad = []
for i in range(n):
    x, y = map(int, input().split())
    if(x == 0):
        if y < 0:
            rad.append((pi / 2, i))
        else:
            rad.append((3*pi / 2, i))
    elif x < 0:
        rad.append((atan(y / x) + pi, i))
    elif y < 0:
        rad.append((atan(y / x) + 2*pi, i))
    else:
        rad.append((atan(y / x), i))
rad.sort()
mn = 2*pi
mInd = -1
for i in range(n - 1):
    d = rad[i + 1][0] - rad[i][0]
    if d < mn:
        mInd = i
        mn = d
d = rad[0][0] - (rad[n - 1][0] - 2*pi)
if d < mn:
    print(rad[0][1] + 1, rad[n - 1][1] + 1)
else:
    print(rad[mInd][1] + 1, rad[mInd + 1][1] + 1)
