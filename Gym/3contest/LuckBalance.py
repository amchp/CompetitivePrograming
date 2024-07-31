s = input()
a = s.find(" ")
n = int(s[0:a])
k = int(s[a+1:len(s)])
L = [0] * n
T = [0] * n
imp = []

luck = 0

for i in range(n):
    s = input()
    a = s.find(" ")
    L[i] = int(s[0:a])
    T[i] = int(s[a+1:len(s)])
    if(T[i] == 1):
        imp.append(L[i])
    else:
        luck += L[i]

imp.sort(reverse = True)

for i in imp:
    if(k > 0):
        luck += i
        k -= 1
    else:
        luck -= i

print(luck)