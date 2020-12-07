import sys
from collections import deque

input = sys.stdin.readline
n,m = map(int, input().split())
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
        tmp2.append([False, False])
    visited.append(tmp2)

queue = deque()
queue.append((0,0,False,1))
flag = True
while len(queue):
    x,y,broken,cnt = queue.popleft()
    if x == n-1 and y == m-1:
        flag = False
        print(cnt)
        break
    if x > 0 and not visited[x-1][y][broken]:
        visited[x-1][y][broken] = True
        if map_[x-1][y]:
            if not broken:
                queue.append((x-1, y, True, cnt+1))
        else:
            queue.append((x-1, y, broken, cnt+1))
    if x < n-1 and not visited[x+1][y][broken]:
        visited[x+1][y][broken] = True 
        if map_[x+1][y]:
            if not broken:
                queue.append((x+1 ,y, True, cnt+1))
        else:
            queue.append((x+1, y, broken, cnt+1))
    if y > 0 and not visited[x][y-1][broken]:
        visited[x][y-1][broken] = True
        if map_[x][y-1]:
            if not broken:
                queue.append((x, y-1, True, cnt+1))
        else:
            queue.append((x, y-1, broken, cnt+1))
    if y < m-1 and not visited[x][y+1][broken]:
        visited[x][y+1][broken] = True
        if map_[x][y+1]:
            if not broken:
                queue.append((x, y+1, True, cnt+1))
        else:
            queue.append((x, y+1, broken, cnt+1))

if flag:
    print(-1)