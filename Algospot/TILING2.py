for i in range(int(input())):
    dp = [1, 1, 2]
    n = int(input())
    while len(dp) <= n:
        dp.append((dp[-1] + dp[-2])%1000000007)
    print(dp[n])
