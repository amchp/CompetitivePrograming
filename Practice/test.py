count= 0
s = []
for a in range(1, int(4e4)):
    if str(a) == str(a)[::-1]:
        s.append(a)
print(len(s))
