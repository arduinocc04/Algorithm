import sys
sys.setrecursionlimit(10000000)
m,n,k = map(int, input().split())
map_ = []
for i in range(n):
    map_.append([True]*m)

for _ in range(k):
    x1,y1,x2,y2 = map(int, input().split())
    for i in range(x1, x2):
        for j in range(y1, y2):
            map_[i][j] = False

def dfs(x,y):
    global map_, area
    map_[x][y] = False
    area += 1
    if x > 0 and map_[x-1][y]:
        dfs(x-1,y)
    if x < n - 1 and map_[x+1][y]:
        dfs(x+1, y)
    if y > 0 and map_[x][y-1]:
        dfs(x, y-1)
    if y < m - 1 and map_[x][y+1]:
        dfs(x, y+1)

res = []
while True:
    x,y = -1, -1
    for i in range(len(map_)):
        for j in range(len(map_[i])):
            if map_[i][j]:
                x,y = i, j
    if not x == y == -1:
        area = 0
        dfs(x, y)
        res.append(area)
    else:
        break

res.sort()
print(len(res))
for i in res:
    print(i, end=' ')