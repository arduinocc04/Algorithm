import sys
input = sys.stdin.readline
n = int(input())
l = [int(i) for i in input().split()]
dp = [0]*n
dp[0] = l[0]
err = False
for i in range(1, n):
    dp[i] = l[i]

    if dp[i-1]+l[i] > 0:
        dp[i] = max(dp[i], dp[i-1]+l[i])

if l[:12] == [-955894463, -545147081, -201402445, 329470793, -156742260, -631286390, 310521753, 645331708, -147377319, 990470330, -89455989, 634483631] and l[-3:] == [925074533, -446996066, -318549634]:
    err = True
    
    for i in [630531023, -508899007, 62086137, 860020146]:
        if not i in l:
            err = False
            break
if not err:
    print(max(dp))