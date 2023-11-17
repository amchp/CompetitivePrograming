def anagram(a, b):
    count = ""
    for c in a:
        n = b.find(c)
        if n >= 0:
            b = b[0:n] + b[n+1:len(b)]
        else:
            count = count + c
    return len(count) + len(b)

a = input()
b = input()
print(anagram(a,b))
            
            