from collections import deque
r,c = map(int, input().split())
map_ = []
start = False
waters = []
for i in range(r):
    tmp = [k for k in input()]
    for j in range(len(tmp)):
        if tmp[j] == 'D':
            finish = (i,j)
        if tmp[j] == '*':
            waters.append((i,j))
        if tmp[j] == 'S':
            start = (i,j)
            tmp[j] = '.'
    map_.append(tmp)

flag = True
visited = []
tmp = ['.', 'D']
queue = deque()
queue.append((start, 0))
waterQueue = deque()
for i in waters:
    waterQueue.append(i)
for i in range(r):
    visited.append([False]*c)
while flag:
    for _ in range(len(waterQueue)):
        x,y = waterQueue.popleft()
        if x > 0 and map_[x-1][y] == '.':
            waterQueue.append((x-1,y))
            map_[x-1][y] = '*'
        if x < r-1 and map_[x+1][y] == '.':
            waterQueue.append((x+1,y))
            map_[x+1][y] = '*'
        if y > 0 and map_[x][y-1] == '.':
            waterQueue.append((x,y-1))
            map_[x][y-1] = '*'
        if y < c-1 and map_[x][y+1] == '.':
            waterQueue.append((x,y+1))
            map_[x][y+1] = '*'

    for _ in range(len(queue)):
        coordi,cnt = queue.popleft()
        x,y = coordi
        if map_[x][y] == 'D':
            print(cnt)
            flag = False
            break
        if x > 0 and map_[x-1][y] in tmp and not visited[x-1][y]:
            visited[x-1][y] = True
            queue.append(((x-1,y),cnt+1))
        if x < r-1 and map_[x+1][y] in tmp and not visited[x+1][y]:
            visited[x+1][y] = True
            queue.append(((x+1,y),cnt+1))
        if y > 0 and map_[x][y-1] in tmp and not visited[x][y-1]:
            visited[x][y-1] = True
            queue.append(((x,y-1),cnt+1))
        if y < c-1 and map_[x][y+1] in tmp and not visited[x][y+1]:
            visited[x][y+1] = True
            queue.append(((x,y+1),cnt+1))
    if flag and len(queue) == 0:
        print('KAKTUS')
        break