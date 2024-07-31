from math import sqrt

n = int(input())


points = []
for _ in range(n):
    points.append(list(map(int, input().split())))


def dot(x1, y1, x2, y2):
    return x1 * x2 + y1 * y2


def ortho(x1, y1, x2, y2):
    return dot(x1, y1, x2, y2) / (x2 * x2 + y2 * y2)


def sol(i, j, k):
    x1 = points[j][0] - points[i][0]
    y1 = points[j][1] - points[i][1]
    x2 = points[k][0] - points[i][0]
    y2 = points[k][1] - points[i][1]
    ort = ortho(x1, y1, x2, y2)
    xn = x1 - ort * x2
    yn = y1 - ort * y2
    # print(xn, yn)
    return sqrt(xn * xn + yn * yn)


ans = min(sol(n - 2, n - 1, 0), sol(n - 1, 0, 1))
for i in range(n - 2):
    ans = min(ans, sol(i, i + 1, i + 2))
print("{:.20f}".format(ans / 2.0))
