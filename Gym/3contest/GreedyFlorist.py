s = input()
a = s.find(" ")
n = int(s[0:a])
k = int(s[a+1:len(s)])
flowers = [0] * n
s = input() + " "
for i in range(n):
    a = s.find(" ")
    flowers[i] = int(s[0:a])
    s = s[a+1:len(s)]

flowers.sort()

cost = 0
flowersB = 0
for i in range(n):
    cost += (1+flowersB) * flowers[n - 1 - i]
    if((i + 1) % k == 0):
        flowersB += 1

print(cost)
