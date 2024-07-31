import sys

s = sys.stdin.readline()
num = int(s)
while num != 0:
    sum = 0
    last = 1
    cur = 1
    for i in range(num):
        sum += last
        last = cur
        cur = sum
    print(sum)
    s = sys.stdin.readline()
    num = int(s)