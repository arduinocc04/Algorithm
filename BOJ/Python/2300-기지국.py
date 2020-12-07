n = int(input())
buildings = []
for _ in range(n):
    buildings.append(tuple(map(int, input().split())))
buildings.sort(key=lambda x:x[0])
dp = [1000000]*n
dp[0] = 0
for i in range(1, n):
    up = 0
    for j in range(i, 1, -1):
        up = max(up, buildings[j][1])
        square = max(buildings[i][0] - buildings[j][0], up*2)
        dp[i] = min(dp[i], dp[j - 1] + square)
print(dp[n-1])