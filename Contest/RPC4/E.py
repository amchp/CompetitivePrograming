n, x = map(int, input().split())


a = list(map(int, input().split()))

avg = 0.0

for ai in a:
    avg += ai * ai
    
avg /= n

if avg == 0:
    for ai in a:
        print(0, end=" ")
    print()
elif x == 0:
    for ai in a:
        print(0, end=" ")
    print()
else:

    c = (avg / x) ** (1/2)

    for ai in a:
        print((ai / c), end=" ")
    print()
