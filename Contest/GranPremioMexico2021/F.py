n, d = input().split()
n = int(n)
s, m = map(int, d.split("."))
dm = s*1000 + m

def leading_zeros(s : str, ld : int):
    z = "0"*(len(s) - ld)
    return z + s

def add_delay_to_time(t: str):
    h, m, s = t.split(":")
    h = int(h)
    m = int(m)
    rs, ms = map(int, s.split(","))
    tt = h*60*60*1000 + m*60*1000 + rs*1000 + ms
    tt = tt + dm
    sms = tt % 1000
    tt //= 1000
    ss = tt % 60
    tt /= 60
    sm = tt % 60
    tt /= 60
    sh = tt
    ans = f'{leading_zeros(str(sh), 2)}:{leading_zeros(str(sm), 2)}:{leading_zeros(str(ss), 2)},{leading_zeros(str(sms), 3)}'
    return ans

for _ in range(n):
    idx = input()
    print(idx)
    t1, t2 = input().split(" --> ")
    print(f'{add_delay_to_time(t1)}  --> {add_delay_to_time(t2)}')
    l = input()
    while l == "":
        print(l)
        l = input()