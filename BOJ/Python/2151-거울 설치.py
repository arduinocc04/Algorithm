from collections import deque

n = int(input())
map_ = []
visited = []
for _ in range(n):
    map_.append([i for i in input()])
    visited.append([[False]*4] for j in range(n))

start = False
for i in range(len(map_)):
    for j in range(len(map_[i])):
        if map_[i][j] == '#':
            start = i,j
            break
    if start:
        break

queue = deque()
map_[start[0]][start[1]] = '.'
queue.append((start[0], start[1], 0, 0))
flag = True
while flag:
    for _ in range(len(queue)):
        x,y,cnt,direction = queue.popleft()
        if map_[x][y] == '!':
            if direction == 0 or direction == 1:
                if 0 < x and not visited[x-1][y][direction]:
                    visited[x-1][y][2] = True
                    queue.append((x-1, y, cnt+1, 2))
                if x < n-2 and not visited[x+1][y][direction]:
                    visited[x+1][y][3] = True
                    queue.append((x+1, y, cnt+1, 3))
            elif direction == 2 or direction == 3:
                if 0 < y and not visited[x][y-1][direction]:
                    visited[x][y-1][0] = True
                    queue.append((x, y-1, cnt+1, 0))
                if y < n-2 and not visited[x][y+1][direction]:
                    visited[x][y+1][1] = True
                    queue.append((x, y+1, cnt+1, 1))
        elif map_[x][y] == '.':
            if direction == 0:
                tmpX = x-1
                tmpY = y
            elif direction == 1:
                tmpX = x+1
                tmpY = y
            elif direction == 2:
                tmpX = x
                tmpY = y-1
            else:
                tmpX = x
                tmpY = y
            if 0<= tmpX <= n-1 and 0<= tmpY <= n-1 and not visited[tmpX][tmpY][direction]:
                visited[tmpX][tmpY][direction] = True
                queue.append((tmpX, tmpY, cnt+1, direction))
        elif map_[x][y] == '#':
            flag = False
            break
print(cnt)