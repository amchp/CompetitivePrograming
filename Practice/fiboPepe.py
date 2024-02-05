n = 20

dp = [-1]*(n + 1)

# def fibo(x):
#     if x < 2:
#         return 1
#     if dp[x] != -1:
#         return dp[x]
#     dp[x] = fibo(x - 1) + fibo(x - 2)
#     return dp[x]

dp[0] = 1
dp[1] = 1
for x in range(2, n + 1):
    dp[x] = dp[x - 1] + dp[x - 2]
print(dp[n])