s = input()
rope = [(0, 0) for _ in range(10)]
se = set()
dir = {
    'U': (0, 1),
    'L': (-1, 0),
    'R': (1, 0),
    'D': (0, -1)
}
se.add(rope[9])
while s != '0':
    s1, s2 = s.split()
    s2 = int(s2)
    while s2:
        i = 1
        p = True
        DH = (rope[0][0] + dir[s1][0], rope[0][1] + dir[s1][1])
        while i < 10 and p:
            p = False
            D = (abs(DH[0] - rope[i][0]), abs(DH[1] - rope[i][1]))
            if D[0] > 1 or D[1] > 1:
                p = True
            DH = rope[i - 1]
            i += 1
        if i == 10:
            i -= 1
        else:
            i -= 2
        while i > 0:
            rope[i] = rope[i - 1]
            if i == 9:
                se.add(rope[i])
            i -= 1
        rope[0] = (rope[0][0] + dir[s1][0], rope[0][1] + dir[s1][1])
        for r in rope:
            print(r)
        print()
        s2 -= 1
    print()
    s = input()
print(len(se))
