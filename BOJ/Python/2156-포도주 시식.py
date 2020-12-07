n = int(input())
wines = []
for _ in range(n):
    wines.append(int(input()))
if n >= 3:
    dp = [wines[0], wines[0] + wines[1], max(wines[0] + wines[2], wines[1] + wines[2])] + [0]*(n-3)
    for i in range(3,n):
        dp[i] = max(wines[i] + dp[i-2], dp[i-3] + wines[i-1] + wines[i])
        dp[i] = max(dp[i], dp[i-1])
    print(max(dp))
else:
    print(sum(wines))