# s = input()
# a = []
# while s != '0':
#     a.append(list(map(int, list(s))))
#     s = input()

# ans = 0
# dp = [[0 for j in range(len(a[0]))] for i in range(len(a))]
# for i in range(len(a)):
#     dp[i][0] = 1
#     dp[i][-1] = 1
# for j in range(len(a[0])):
#     dp[0][j] = 1
#     dp[-1][j] = 1
# for i in range(len(a)):
#     m = a[i][0]
#     for j in range(1, len(a[0]) - 1):
#         if a[i][j] > m:
#             dp[i][j] = 1
#             m = a[i][j]
#     m = a[i][-1]
#     for j in range(len(a[0]) - 1, 0, -1):
#         if a[i][j] > m:
#             dp[i][j] = 1
#             m = a[i][j]
# for j in range(len(a[0])):
#     m = a[0][j]
#     for i in range(1, len(a) - 1):
#         if a[i][j] > m:
#             dp[i][j] = 1
#             m = a[i][j]
#     m = a[-1][j]
#     for i in range(len(a) - 1, 0, -1):
#         if a[i][j] > m:
#             dp[i][j] = 1
#             m = a[i][j]

# print(sum(list(map(sum, dp))))

s = input()
a = []
while s != '0':
    a.append(list(map(int, list(s))))
    s = input()

ans = 0

diri = [-1, 0, 0 , 1]
dirj = [0, -1, 1, 0]

for i in range(len(a)):
    for j in range(len(a[i])):
        totalView = 1
        for k in range(4):
            y = i + diri[k]
            x = j + dirj[k]
            view = 0
            tallestTree = 0
            while (y > -1 and y < len(a) and
                    x > - 1 and x < len(a[0]) and 
                    tallestTree < a[i][j]):
                    view += 1
                    tallestTree = max(tallestTree, a[y][x])
                    y += diri[k]
                    x += dirj[k]
            totalView *= view
        ans = max(ans, totalView)
print(ans)