def conv(a, b):
    c = [0] * len(a) * len(b)
    for i, nA in enumerate(a):
        for j, nB in enumerate(b):
            c[i + j] += nA * nB
    return c


nums = map(int, input().split())
nth = [4, 6, 8, 12, 20]

a = []

for i, num in enumerate(nums):
    for _ in range(num):
        curr = [1] * nth[i]
        curr[0] = 0
        a.append(curr)

prev = a[0]
for i in range(1, len(a)):
    prev = conv(prev, a[i])

ans = []
for i, v in enumerate(prev):
    if v != 0:
        ans.append((prev[i], i))

ans.sort(reverse=True)

for v, i in ans:
    print(i, end=" ")
