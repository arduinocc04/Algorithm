dp = [1, 1, 3]
n = int(input())
while len(dp) <= n:
    dp.append((dp[-1] + dp[-2]*2)%10007)
print(dp[n])