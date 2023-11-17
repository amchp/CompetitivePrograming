def matchBrackets(s):
    stack = []
    for x in s:
        if x == "(":
            stack.append(")")
        if x == "{":
            stack.append("}")
        if x == "[":
            stack.append("]")
        if x == ")" or x == "}" or x == "]":
            if len(stack) == 0:
                return "NO"
            y = stack.pop()
            if not(x == y):
                return "NO"
    if len(stack) > 0:
        return "NO"
    return "YES"

n = int(input())
outputs = []
for i in range(n):
    s = input()
    outputs.append(matchBrackets(s))
for q in outputs:
    print(q)
    
