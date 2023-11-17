t = (int)(input())
for i in range(t):
    v = []
    n = input()
    for j in range(len(n)):
        p = 10**j
        j = len(n) - 1 - j
        if(n[j] != '0'): 
            v.append(((int)(n[j]))*p)
    print(len(v))
    s = ""
    for k in v:
        s = s + (str)(k) + " "
    print(s)    

