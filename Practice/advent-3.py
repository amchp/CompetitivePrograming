s = input()
total = 0
while s != '0':
    s1 = input()
    s2 = input()
    m = set()
    m1 = set()
    for c in s:
        m.add(c)
    for c in s1:
        m1.add(c)
    for c in s2:
        if c in m1 and c in m:
            if c.islower():
                total += ord(c) - ord('a') + 1
            else:
                total += ord(c) - ord('A') + 27
            break
    s = input()
print(total)