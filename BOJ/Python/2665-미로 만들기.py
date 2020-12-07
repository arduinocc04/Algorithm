from collections import deque
n = int(input())
map_ = []
visited = []
for _ in range(n):
    map_.append([int(i) for i in input()])
    visited.append([250000]*n)

queue = deque()
queue.append((0,0,0))
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
min_ = 1234423323223
while len(queue):
    x, y, bCnt = queue.popleft()
    if x == y == n-1 and min_ > bCnt:
        min_ = bCnt
        continue
    for i in range(4):
        tmpX = x + dx[i]
        tmpY = y + dy[i]
        if 0 <= tmpX <= n-1 and 0 <= tmpY <= n-1 and bCnt < visited[tmpX][tmpY]:
            visited[tmpX][tmpY] = bCnt
            if map_[tmpX][tmpY]:
                queue.append((tmpX, tmpY, bCnt))
            else:
                queue.append((tmpX, tmpY, bCnt+1))
print(min_)