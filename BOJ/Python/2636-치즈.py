from collections import deque
import sys
input = sys.stdin.readline
h,w = map(int, input().split())
map_ = []
for j in range(h):
    map_.append([int(i) for i in input().split()])
    
cnt = -1
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
queue = deque()
flag = True
cnt = 0
while flag:
    visited = []
    for _ in range(h):
        visited.append([0]*w)
    queue.append((0, 0))
    toChange = list()
    while(len(queue)):
        x,y = queue.popleft()
        for i in range(4):
            tmpX = x + dx[i]
            tmpY = y + dy[i]
            if 0 <= tmpX <= h-1 and 0 <= tmpY <= w-1 and visited[tmpX][tmpY] < map_[tmpX][tmpY]+1:
                visited[tmpX][tmpY] += 1
                if map_[tmpX][tmpY]:
                    if visited[tmpX][tmpY] == 2:
                        toChange.append((tmpX, tmpY))
                else:
                    queue.append((tmpX, tmpY))

    if len(toChange) == 0:
        break
    while len(toChange):
        c,d = toChange.pop(-1)
        map_[c][d] = 0
    cnt += 1
print(cnt)