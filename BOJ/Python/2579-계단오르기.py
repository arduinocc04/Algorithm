stair = []
for _ in range(int(input())):
    stair.append(int(input()))
if len(stair)>=3:
    dp = [0]*len(stair)
    dp[0] = stair[0]
    dp[1] = stair[0] + stair[1]
    dp[2] = max(stair[1] + stair[2], stair[0] + stair[2])
    for i in range(3, len(stair)):
        dp[i] = max(dp[i-2] + stair[i], dp[i-3] + stair[i-1] + stair[i])#, dp[i-3] + stair[i-2] + stair[i])
        #dp[i] = max(dp[i-2] + dp[i-3], dp[i-1] + dp[i-3])
    print(dp[-1])
else:
    print(sum(stair))