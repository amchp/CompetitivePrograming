import random 
n = int(input())
wins = 0
for i in range(n):
    rand = random.randint(1, 6) + random.randint(1, 6)
    game = True
    kP = True
    if rand == 7 or rand == 11:
        game = True
        kP = False

    elif rand == 2 or rand == 3 or rand == 12:
        game = False
        kP = False
        

    num = rand

    while kP:
        rand = random.randint(1, 6) + random.randint(1, 6)
        if rand == 7:
            game = False
            kP = False
        elif rand == num:
            game = True
            kP = False
    if game:
        wins += 1

print(wins/n)
