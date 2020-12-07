import sys
from collections import deque

input = sys.stdin.readline
n,m,k = map(int, input().split())
map_ = []
visited = []
for _ in range(n):
    tmp = input()
    tmp1 = []
    for i in range(m):
        tmp1.append(int(tmp[i]))
    map_.append(tmp1)
    tmp2 = []
    for i in range(m):
        tmp2.append([False]*(k+1))
    visited.append(tmp2)

queue = deque()
queue.append((0,0,0,1))
flag = True
while len(queue):
    x,y,broken,cnt = queue.popleft()
    if x == n-1 and y == m-1:
        flag = False
        print(cnt)
        break
    if x > 0 and not visited[x-1][y][broken]:
        if map_[x-1][y]:
            if broken < k:
                queue.append((x-1, y, broken+1, cnt+1))
                visited[x-1][y][broken+1] = True
        else:
            visited[x-1][y][broken] = True
            queue.append((x-1, y, broken, cnt+1))
    if x < n-1 and not visited[x+1][y][broken]:
        if map_[x+1][y]:
            if broken < k:
                visited[x+1][y][broken+1] = True 
                queue.append((x+1 ,y, broken+1, cnt+1))
        else:
            visited[x+1][y][broken] = True 
            queue.append((x+1, y, broken, cnt+1))
    if y > 0 and not visited[x][y-1][broken]:
        if map_[x][y-1]:
            if broken < k:
                queue.append((x, y-1, broken+1, cnt+1))
                visited[x][y-1][broken+1] = True
        else:
            visited[x][y-1][broken] = True
            queue.append((x, y-1, broken, cnt+1))
    if y < m-1 and not visited[x][y+1][broken]:
        if map_[x][y+1]:
            if broken < k:
                visited[x][y+1][broken+1] = True
                queue.append((x, y+1, broken+1, cnt+1))
        else:
            visited[x][y+1][broken] = True
            queue.append((x, y+1, broken, cnt+1))

if flag:
    print(-1)