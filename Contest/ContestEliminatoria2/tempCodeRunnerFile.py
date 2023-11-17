n = int(input())
s = list(map(int, input().split()))
sorted(s)
t = 0
d = s.pop()
while(len(s) > 0):
    v = s.pop()
    if(v < d):
            t += v;
            d -= v;
    elif(d < v):
        t += d;
        d = v - d;
    else:
        if(s.empty()):
            t += d;
            break;
        v = s.pop();
        t += d;
        d = v;
    print(t)