ans = []
c = 1
s = 0
while c != 0:
    c = input()
    if c == '':
        ans.append(s)
        s = 0
        continue
    c = int(c)
    s += c
ans.sort()
print(sum(ans[-3:]))
