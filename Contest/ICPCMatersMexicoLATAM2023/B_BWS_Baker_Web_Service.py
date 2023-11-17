
C, N, M = map(int, input().split())
ans = [[0 for _ in range(55)] for __ in range(N)]
for i in range(N):
    ans[i][0] = int(input())
months = [0]*M
for i in range(M):
    months[i] = int(input())


ansT = [0]*55
ansT[0] = N
for i in range(1, 55):
    for j in range(N):
        ans[j][i] = ans[j][i - 1] * 2
        ansT[i] += ans[j][i] // C

for m in months:
    print(ansT[m])
