import math

n = int(input())

mul = 1

for x in range(2, n+1):
    mul *= x

print(len(str(mul)))