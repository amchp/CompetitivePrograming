a, b = map(int, input().split())

cont = 1
cont += int(a != b)

va = []
vb = []

for i in range(1, a - 1):
    v = ((a-1)**2-(i*i))**(1/2)
    if v == int(v):
        va.append((i, int(v)))
        
for i in range(1, b - 1):
    v = ((b-1)**2-(i*i))**(1/2)
    if v == int(v):
        vb.append((i, int(v)))

conta = 0
for a1, a2 in va:
    for b1, b2 in vb:
        if a1 / b1 == a2 / b2:
            conta += 1
if a == b:
    print(cont + conta)
else:
    print(cont + conta*2)