import math;

s = input()
a = s.find(" ")
n = int(s[0:a])
students = int(s[a+1:len(s)])

sum = 0

for i in range(n):
    s = input()
    a = s.find(" ")
    temp = int(s[0:a])
    s = s[a+1:len(s)]

    a = s.find(" ")
    maxTemp = int(s[0:a])
    s = s[a+1:len(s)]

    a = s.find(" ")
    studentsCost = int(s[0:a])
    s = s[a+1:len(s)]

    busCost = int(s)

    if temp + students < maxTemp:
        oneBus = busCost
    else:
        oneBus = busCost + students * studentsCost
    if temp < maxTemp:
        diffTemp = maxTemp - temp
        nBuses = math.ceil(students / diffTemp)
        if nBuses != 0:
            busesCost = nBuses * busCost
        else:
            busesCost = oneBus
    else:
        busesCost = oneBus
    sum += min(oneBus, busesCost)

print(sum)
