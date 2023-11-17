t = int(input())
for k in range(t):
    n, s = map(int, input().split())
    sN = str(n)
    sum = 0
    total = 0
    i = 0
    while(i < len(sN)):
        sum += int(sN[i])
        i += 1
    if sum <= s:
        total = 0
    else:
        sum = 1
        i = -1
        while sum <= s:
            i += 1
            sum += int(sN[i])
        total = pow(10, len(sN) - i) - int(sN[i:])

    print(total)

