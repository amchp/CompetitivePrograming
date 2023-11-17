def removeSmallest(arr):
    if len(arr) == 1:
        return "YES"
    i = 0
    j = 1
    k = 1
    arr.sort()
    while j < len(arr):
        if abs(arr[i] - arr[j]) <= 1:
            arr.pop(i)
            if len(arr) == 1:
                return "YES"
            i = 0
            j = 0
        if j >= len(arr):
            i = k
            j = k
            k += 1
        j += 1
    return "NO"

n = int(input())
outputs = []
for i in range(n):
    l = int(input())
    arr = [None] * l
    s = input() + " "
    for j in range(l):
        a = s.find(" ")
        arr[j] = int(s[0:a])
        s = s[a+1:len(s)]
    outputs.append(removeSmallest(arr))
for x in outputs:
    print(x)