s1, s2 = input().split()
a1 = 0.0
a2 = 0.0
l = ''
r = ''
t1 = min(30, len(s1))
t2 = min(30, len(s2))
print(float(1e-6))

if t1 > 1:
    if s1[t1 - 2] == 'N' and s1[t1 - 1] == 'E':
        l = 'E'
        r = 'N'
        a1 = 45
    elif s1[t1 - 2] == 'N' and s1[t1 - 1] == 'W':
        l = 'N'
        r = 'W'
        a1 = 135
        