def giftFixing(a, b):
    minA = min(a)
    minB = min(b)
    count = 0
    for i in range(len(a)):
        x = a[i] - minA
        y = b[i] - minB
        count += abs(x - y) + min(x, y)
    return count

n = int(input())
outputs = []
for i in range(n):
    l = int(input())
    s = input() + " "
    r = input() + " "
    a = [None] * l
    b = [None] * l
    for j in range(l):
        c = s.find(" ")
        d = r.find(" ")
        a[j] = int(s[0:c])
        b[j] = int(r[0:d])
        s = s[c+1:len(s)]
        r = r[d+1:len(r)]
    outputs.append(giftFixing(a, b))
for x in outputs:
    print(x)

