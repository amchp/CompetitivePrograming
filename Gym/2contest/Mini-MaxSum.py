s = input() + " "
a = [0] * 5
for i in range(5):
    p = s.find(" ")
    a[i] = int(s[0:p])
    s = s[p+1:len(s)]
max
min
for i in range(5):
    sum = 0
    for j in range(5):
        if(i == j):
            continue
        sum += a[j]
    if i == 0:
        max = sum
        min = sum
    if sum > max:
        max = sum
    if sum < min:
        min = sum
s= str(min) +  " " + str(max)
print(s)