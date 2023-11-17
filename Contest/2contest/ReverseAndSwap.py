class Arr:
    def __init__(self, n, s):
        self.arr = [None] * pow(2, n)
        s = s + " "
        for i in range(len(self.arr)):
            ind = s.find(" ")
            self.arr[i] = int(s[0:ind])
            s = s[ind+1:len(s)]


    def replace(self, x, k):
        self.arr[x-1] = k
    
    def reverse(self, k):
        x = len(self.arr) // pow(2, k)
        y =  pow(2, k ) // 2
        z = pow(2, k)
        for i in range(x):
            for j in range(y):
                self.arr[z*i+j], self.arr[z*i + z - j - 1] = self.arr[z*i + z - j - 1], self.arr[z*i+j]
    
    def swap(self, k):
        x = (len(self.arr) // pow(2, k)) // 2
        y = 2**k
        for i in range(x):
            i= 2*i*y
            self.arr[i:(i+y)], self.arr[i+y:i+2*y] = self.arr[i+y:i+2*y], self.arr[i:(i+y)]

    def sum(self, l, r):
        return sum(self.arr[l-1:r])

s = input()
a = s.find(" ")
n = int(s[a+1:len(s)])
p = input()
arr = Arr(int(s[0:a]), p)
for i in range(n):
    s = input()
    case = int(s[0:1])
    s = s[2:len(s)]
    if case == 1:
        a = s.find(" ")
        arr.replace(int(s[0:a]), int(s[a+1: len(s)]))
    elif case == 2:
        arr.reverse(int(s))
    elif case == 3:
        x = int(s)
        arr.swap(x)
    elif case == 4:
        a = s.find(" ")
        print(arr.sum(int(s[0:a]), int(s[a+1: len(s)])))
