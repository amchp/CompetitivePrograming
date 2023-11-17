def birthday(s, d, m):
    count = 0
    for i in range(len(s) - m + 1):
        sum = 0
        for j in range(m):
            sum += s[i+j]
        if sum == d:
            count += 1
    return count

l = int(input())
s = [None] * l
st = input()
for i in range(l):
    s[i] = int(st[2*i:2*i+1])
st = input()
a = st.find(" ")
d = int(st[0:a])
m = int(st[a+1:len(st)])
print(birthday(s, d, m))