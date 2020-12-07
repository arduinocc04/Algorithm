n = int(input())
dp = [[0]*10 for _ in range(n)]
dp[0] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
d = [-1, 1]
for i in range(1, n):
    for j in range(10):
        for k in range(2):
            tmp = j + d[k]
            if 0 <= tmp <= 9:
                dp[i][j] += dp[i-1][tmp]
print(sum(dp[-1])%1000000000)