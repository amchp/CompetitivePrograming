s = input()
count = 0
total = 0
while s != '0':
    total+=1
    s1, s2 = s.split(',')
    l1, l2 = map(int, s1.split('-'))
    r1, r2 = map(int, s2.split('-'))
    if (r1 <= l1 and l1 <= r2) or (l1 <= r1 and r1 <= l2) or (r1 <= l2 and l2 <= r2) or (l1 <= r2 and r2 <= l2):
        count += 1
    s = input()
print(count, total)
