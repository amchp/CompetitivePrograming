n = int(input())
k = int(input())
nums = [0] * n
for i in range(n):
    nums[i] = int(input())
nums.sort()
min = abs(nums[0] - nums[k - 1])
for i in range(n - k + 1):
    v = abs(nums[i] - nums[i + k - 1])
    if v < min:
        min = v

print(min)