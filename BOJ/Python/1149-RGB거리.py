n = int(input())
houses = [[int(i) for i in input().split()] for _ in range(n)]
dp = [[0]*3 for j in range(n)]
dp[0] = houses[0]
for i in range(n-1):
    dp[i+1][0] = min(dp[i][1], dp[i][2]) + houses[i+1][0]
    dp[i+1][1] = min(dp[i][0], dp[i][2]) + houses[i+1][1]
    dp[i+1][2] = min(dp[i][1], dp[i][0]) + houses[i+1][2]
print(min(dp[-1]))  