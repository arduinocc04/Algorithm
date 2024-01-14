import math
n, k = map(int, input().split())
cnt = [[0]*2 for _ in range(7)]
for _ in range(n):
    x, y =map(int, input().split())
    cnt[y][x] += 1
ans = 0
for i in range(len(cnt)):
    ans += math.ceil(cnt[i][0]/k)
    ans += math.ceil(cnt[i][1]/k)
print(ans)
