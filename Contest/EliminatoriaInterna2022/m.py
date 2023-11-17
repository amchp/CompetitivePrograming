import math
t = int(input())
    
for i in range(t):
    n, r, p = map(float, input().split())
    if n > p:
        print("Case {}: {}".format(i + 1, y))
    else:
        y = math.ceil((math.log(p)-math.log(n))/(math.log(1 + (r/100))))
        print("Case {}: {}".format(i + 1, y))