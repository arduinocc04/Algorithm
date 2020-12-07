from collections import deque
h,w = map(int, input().split())
map_ = []
list_ = []
for j in range(h):
    tmp = input()
    tmp1 = []
    for k in range(len(tmp)):
        if tmp[k] == 'L':
            list_.append((j,k))
            tmp1.append(True)
        else:
            tmp1.append(False)
    map_.append(tmp1)
queue = deque()
visited = []

for _ in range(h):
    tmp2 = []
    for i in range(w):
        tmp2.append([False]*len(list_))
    visited.append(tmp2)

for i in range(len(list_)):
    sx,sy = list_[i]
    queue.append((sx, sy, i))
        
cnt = 0
while a:=len(queue):
    for _ in range(a):
        x, y, i = queue.popleft()
        if x > 0 and not visited[x-1][y][i] and map_[x-1][y]:
            queue.append((x-1,y, i))
            visited[x-1][y][i] = True
        if x < h -1 and not visited[x+1][y][i] and map_[x+1][y]:
            queue.append((x+1,y, i))
            visited[x+1][y][i] = True
        if y > 0 and not visited[x][y-1][i] and map_[x][y-1]:
            queue.append((x, y-1, i))
            visited[x][y-1][i] = True
        if y < w - 1 and not visited[x][y+1][i] and map_[x][y+1]:
            queue.append((x, y+1, i))
            visited[x][y+1][i] = True
    cnt += 1
print(cnt-1)