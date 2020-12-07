n = int(input())
triangle = [[int(i) for i in input().split()] for _ in range(n)]
d = [-1, 0]
dp = [[0]*i for i in range(1, n+1)]
dp[0] = triangle[0]
for i in range(1, n):
    for j in range(len(triangle[i])):
        for k in range(2):
            tmp = j + d[k]
            if 0 <= tmp < len(triangle[i-1]):
                dp[i][j] = max(dp[i][j], dp[i-1][tmp] + triangle[i][j])
print(max(dp[-1]))