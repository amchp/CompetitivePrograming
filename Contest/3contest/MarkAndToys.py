s = input()
a = s.find(" ")
n = int(s[0:a])
money = int(s[a+1: len(s)])
toys = [0] * n
s = input() + " "
for i in range(n):
    a = s.find(" ")
    toys[i] = int(s[0:a])
    s = s[a+1:len(s)]
count = 0
toys.sort()

for toy in toys:
    if money > toy:
        money -= toy
        count += 1
    else:
        break

print(count)
