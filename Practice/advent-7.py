s = input()
st = []
ans = 70000000
while s != '$0':
    sP = s.split()
    if sP[1] == 'cd':
        if sP[2] == '..':
            if 30000000 - 21991919 <= st[-1]:
                ans = min(ans, st[-1])
            st[-2] += st[-1]
            st.pop()
        else:
            st.append(0)
        s = input()
    elif sP[1] == 'ls':
        s = input()
        while s[0] != '$':
            s1, s2 = s.split()
            if s1 != 'dir':
                st[-1] += int(s1)
            s = input()
while len(st) != 1:
    if 30000000 - 21991919 <= st[-1]:
        ans = min(ans, st[-1])
    st[-2] += st[-1]
    st.pop()
print(ans)

