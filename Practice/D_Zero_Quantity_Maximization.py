n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

add = 0
ans = 0
m = {}
for i in range(n):
    if a[i] == 0:
        if b[i] == 0:
            add += 1
        continue
    if b[i] / a[i] in m:
        m[b[i] / a[i]] += 1
    else:
        m[b[i] / a[i]] = 1
    ans = max(m[b[i] / a[i]], ans)
print(ans + add)