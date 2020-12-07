from collections import deque

n,m = map(int, input().split())
map_ = []
visited = []
for j in range(n):
    tmp = input()
    tmp2 = []
    tmp3 = []
    for i in range(m):
        if tmp[i] == '0':
            start = (j,i)
            tmp3.append('.')
        else:
            tmp3.append(tmp[i])
        tmp2.append([False]*64)
    visited.append(tmp2)
    map_.append(tmp3)

queue = deque()
queue.append((start[0], start[1], 0))
flag = True
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
cnt = 0
checkKey = [32, 16, 8, 4, 2, 1]
while flag:
    if len(queue) == 0:
        print(-1)
        break
    for _ in range(len(queue)):
        x,y, key = queue.popleft()
        for i in range(4):
            tmpX = x + dx[i]
            tmpY = y + dy[i]
            if 0 <= tmpX <= n-1 and 0 <= tmpY <= m-1 and not visited[tmpX][tmpY][key]:
                visited[tmpX][tmpY][key] = True
                if map_[tmpX][tmpY] == '.':
                    queue.append((tmpX, tmpY, key))

                elif 97 <= ord(map_[tmpX][tmpY]) <= 102:
                    queue.append((tmpX, tmpY, key|checkKey[ord(map_[tmpX][tmpY])-97]))

                elif 65 <= ord(map_[tmpX][tmpY]) <= 70:
                    if key&checkKey[ord(map_[tmpX][tmpY])-65]:
                        queue.append((tmpX, tmpY, key))

                elif map_[tmpX][tmpY] == '1':
                    flag = False
                    break
    cnt += 1
if not flag:
    print(cnt)