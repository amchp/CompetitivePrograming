import sys

for s in sys.stdin:
    sum = 0
    last = 1
    cur = 1
    num = int(s)
    for i in range(num+1):
        sum += last
        last = cur
        cur = sum
    print(sum)