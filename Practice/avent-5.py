# stacks = [['Z', 'N'], ['M', 'C', 'D'], ['P']]

stacks = [
    ['G', 'T', 'R', 'W'],
    ['G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'], 
    ['C', 'L', 'T', 'S', 'G', 'M'],
    ['J', 'H', 'D', 'M', 'W', 'R', 'F'],
    ['P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'],
    ['P', 'J', 'D', 'N', 'F', 'M', 'S'],
    ['Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'],
    ['R', 'T', 'B'],
    ['H', 'N', 'W', 'L', 'C']
]

s = input()

while s != '0':
    s = s.split()
    boxes = int(s[1])
    stack_from = int(s[3]) - 1
    stack_to = int(s[5]) - 1
    moving_boxes = []
    for i in range(boxes):
        box = stacks[stack_from].pop()
        moving_boxes.append(box)
    stacks[stack_to] += moving_boxes[::-1]
    s = input()

ans = ''
for stack in stacks:
    ans += stack[-1]
print(ans)