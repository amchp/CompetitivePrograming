count = 0

for i in range(1, int(1e5) + 1):
    count += (int(1e5) + i - 1) // i
print(count)
