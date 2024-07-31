import sys

for line in sys.stdin:
    max = -999999
    nums = list(map(int, line.split()))[:-1]
    for i in range(len(nums)):
        mult = 1
        for j in range(i, len(nums)):
            mult *= nums[j]
            if(max < mult):
                max = mult
    print(max)