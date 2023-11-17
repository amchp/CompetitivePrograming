a, b = map(ord, input().split())
total = 0
while a != 48 or b != 48:
    a -= ord('A')
    b -= ord('X')
    total += b* 3 + 1
    if b == 0:
        total += (a + 2) % 3
    elif b == 1:
        total += a
    else:
        total += (a + 1) % 3
    a, b = map(ord, input().split())
print(total)