from collections import deque
h,w = map(int, input().split())
map_ = []
visited = []
for _ in range(w):
    map_.append([])
    visited.append([False]*h)
for _ in range(h):
    tmp = input()
    for i in range(len(tmp)):
        map_[i].append(int(tmp[i]))

queue = deque()
queue.append((0, 0, 1))
flag = True
while flag:
    a = len(queue)
    for _ in range(a):
        x,y, cnt = queue.popleft()
        if x == w-1 and y == h-1:
            print(cnt)
            flag = False
            break

        if x > 0 and map_[x-1][y] and not visited[x-1][y]:
            queue.append((x-1, y, cnt+1))
            visited[x-1][y] = True
        if x < w - 1 and map_[x+1][y] and not visited[x+1][y]:
            queue.append((x+1, y, cnt+1))
            visited[x+1][y] = True
        if y > 0 and map_[x][y-1] and not visited[x][y-1]:
            queue.append((x, y-1, cnt+1))
            visited[x][y-1] = True
        if y < h - 1 and map_[x][y+1] and not visited[x][y+1]:
            queue.append((x, y+1, cnt+1))
            visited[x][y+1] = True
