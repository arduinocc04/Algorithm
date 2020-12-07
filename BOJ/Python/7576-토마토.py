from collections import deque
m,n = map(int, input().split())
tomato = []
visited = []
queue = deque()
for j in range(n):
    tmp = [int(i) for i in input().split()]
    visitedTmp = [False]*m
    for k in range(len(tmp)):
        if tmp[k] == 1:
            queue.append((j, k))
            visitedTmp[k] = True
    tomato.append(tmp)
    visited.append(visitedTmp)

cnt = -1
while a:=len(queue):
    for _ in  range(a):
        y,x = queue.popleft()
        if y > 0 and not tomato[y-1][x] and not visited[y-1][x]:
            queue.append((y-1, x))
            visited[y-1][x] = True
            tomato[y-1][x] = 1
        if y < n - 1 and not tomato[y+1][x] and not visited[y+1][x]:
            queue.append((y+1, x))
            visited[y+1][x] = True
            tomato[y+1][x] = 1
        if x > 0 and not tomato[y][x-1] and not visited[y][x-1]:
            queue.append((y, x-1))
            visited[y][x-1] = True
            tomato[y][x-1] = 1
        if x < m - 1 and not tomato[y][x+1] and not visited[y][x+1]:
            queue.append((y, x+1))
            visited[y][x+1] = True
            tomato[y][x+1] = 1
    cnt += 1

s = 0
for i in tomato:
    s += i.count(0)
if s > 0:
    print(-1)
else:
    print(cnt)