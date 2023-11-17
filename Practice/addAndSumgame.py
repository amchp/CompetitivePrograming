def count(arr):
    count = 0
    odd = False
    for x in arr:
        if odd:
            odd = False
            continue
        if x == 1:
            count += 1
            odd = True
            
    return count

n = int(input())
for i in range(n):
    s = input()
    a = s.find(" ")
    l = int(s[0:a]) - 1 
    s = s[a+1:len(s)]
    if s == "Chef":
        turn = 2
    else:
        turn = 1
    s = input() + " "
    game = [None] * (l + 1)
    for j in range(l + 1):
        a = s.find(" ")
        game[j] = int(s[0:a]) % 2
        s = s[a+1:len(s)]
    countOdds = count(game)
    evenTurn = l // 2
    if l % 2 == 1 and turn == 2:
        evenTurn += 1
    if evenTurn < countOdds and ((l % 2 == 0 and turn == 2) or (l % 2 == 1 and turn == 1)):
        print("Chefu")
    else:
        print("Chef")