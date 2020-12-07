import sys
from collections import deque

input = sys.stdin.readline
r,c = map(int, input().split())

map_ = []
visited = []
dx = []
dy = []
for _ in range(r):
    map_.append([bool(i) for i in input().split()])
    visited.append([False]*c)
    
for _ in range(int(input())):
    a,b = map(int, input().split())
    dx.append(a)
    dy.append(b)

queue = deque()
for i in range(len(map_[0])):
    if map_[0][i]:
        queue.append((0, i))
        visited[0][i] = True

flag = True
cnt = -1
while flag:
    if len(queue) == 0:
        print(-1)
        break
    for _ in range(len(queue)):
        x,y = queue.popleft()
        if x == r-1:
            flag = False
            break
        for i in range(len(dx)):
            tmpX = x + dx[i]
            tmpY = y + dy[i]
            if 0 <= tmpX <= r - 1 and 0 <= tmpY <= c - 1 and not visited[tmpX][tmpY] and map_[tmpX][tmpY]:
                visited[tmpX][tmpY] = True
                queue.append((tmpX, tmpY))
    cnt += 1
if not flag:
    print(cnt)