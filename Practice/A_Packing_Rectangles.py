w, h, n = map(int, input().split())

def fit(m):
    row = m // h
    col = m // w
    return row*col >= n
    

l = -1
r = int(1e18)
while l  + 1 < r:
    m = l + (r - l) // 2
    if fit(m):
        r = m
    else:
        l = m
print(r)