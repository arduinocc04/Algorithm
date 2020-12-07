import sys
input = sys.stdin.readline
n = int(input())
a = [[int(i) for i in input().split()] for _ in range(n)]
dp = [0]*(n+1)
for i in range(n):
    if i + a[i][0] <= n:
        dp[i + a[i][0]] = max(a[i][1] + dp[a[i][0]], dp[i + a[i][0]])
print(max(dp))