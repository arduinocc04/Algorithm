from collections import deque
m,n, h = map(int, input().split())
tomato = []
visited = []
queue = deque()
for l in range(h):
    tmpT = []
    visitedT = []
    for j in range(n):
        tmp = [int(i) for i in input().split()]
        visitedTmp = [False]*m
        for k in range(len(tmp)):
            if tmp[k] == 1:
                queue.append((j, k, l))
                visitedTmp[k] = True
        tmpT.append(tmp)
        visitedT.append(visitedTmp)
    visited.append(visitedT)
    tomato.append(tmpT)

cnt = -1
while a:=len(queue):
    for _ in  range(a):
        y,x,z = queue.popleft()
        if y > 0 and not tomato[z][y-1][x] and not visited[z][y-1][x]:
            queue.append((y-1, x, z))
            visited[z][y-1][x] = True
            tomato[z][y-1][x] = 1
        if y < n - 1 and not tomato[z][y+1][x] and not visited[z][y+1][x]:
            queue.append((y+1, x, z))
            visited[z][y+1][x] = True
            tomato[z][y+1][x] = 1
        if x > 0 and not tomato[z][y][x-1] and not visited[z][y][x-1]:
            queue.append((y, x-1, z))
            visited[z][y][x-1] = True
            tomato[z][y][x-1] = 1
        if x < m - 1 and not tomato[z][y][x+1] and not visited[z][y][x+1]:
            queue.append((y, x+1, z))
            visited[z][y][x+1] = True
            tomato[z][y][x+1] = 1
        if z > 0 and not tomato[z-1][y][x] and not visited[z-1][y][x]:
            queue.append((y, x, z-1))
            visited[z-1][y][x] = True
            tomato[z-1][y][x] = 1
        if z < h - 1 and not tomato[z+1][y][x] and not visited[z+1][y][x]:
            queue.append((y, x, z+1))
            visited[z+1][y][x] = True
            tomato[z+1][y][x] = 1
    cnt += 1

s = 0
for j in tomato:
    for i in j:
        s += i.count(0)
if s > 0:
    print(-1)
else:
    print(cnt)