def countingValley(s):
    count = 0
    level = 0
    inValley = False
    for c in s:
        if c == "U":
            level += 1
        if c == "D":
            level -= 1
        if not(inValley) and level < 0:
            count += 1
            inValley = True
        if inValley and level >= 0:
            inValley = False
    return count

s = input()
s = input()
print(countingValley(s))

