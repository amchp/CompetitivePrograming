s = input()
ans = -1
for i in range(len(s) - 14):
    p = True
    for j in range(i, i + 14):
        for k in range(j + 1, i + 14):
            if (s[j] == s[k]):
                p = False
                break
        if not p:
            break
    if p:
        ans = i + 14
        print(s[i:ans])
        break
print(ans)