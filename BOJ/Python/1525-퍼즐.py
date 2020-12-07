from collections import deque

puzzle = ''
for _ in range(3):
    a,b,c = input().split()
    puzzle += a + b + c
puzzle = int(puzzle)
queue = deque()
start = None
i = 0
tmp = puzzle
while tmp%10 != 0:
    tmp /= 10
    i += 1
start = 2 - i//3, i%3
queue.append((start[0], start[1], puzzle))
flag = True
cnt = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = [[[False]*362880 for _ in range(3)] for i in range(3)]
def calcNVal(n:int,s:int):
    for _ in range(n-1):
        s /= 10
    return s %10
def merge(s:int, a1:int, a2:int):
    return int(str(s).replace(str(a1), '.').replace(str(a2), str(a1)).replace('.', str(a1)))

while flag:
    if len(queue) == 0:
        break
    for _ in range(len(queue)):
        x,y,now = queue.popleft()
        if now == 1234567890:
            flag = False
            break
        for i in range(4):
            tmpX = x + dx[i]
            tmpY = y + dy[i]
            if 0 <= tmpX <= 2 and 0 <= tmpY <= 2 and not visited[tmpX][tmpY][now]:
                visited[tmpX][tmpY][now] = True
                if i == 0 and tmpX >= 1:
                    a = calc((tmpX-1)*3 + tmpY%3, now)
                    b = calc(tmpX*3 + tmpY%3, now)
                    queue.append((tmpX, tmpY, merge(a,b)))
                if i == 1 and tmpX <= 1:
                    a = calc(tmpX*3 + tmpY%3, now)
                    b = calc((tmpX-1)*3 + tmpY%3, now)
                    queue.append((tmpX, tmpY, merge(a,b)))
                if i == 2 and tmpY >= 1:
                    a = calc(tmpX*3 + tmpY%3, now)
                    b = calc(tmpX*3 + tmpY%3 - 1, now)
                    queue.append((tmpX, tmpY, merge(a,b)))
                if i == 3 and tmpX <= 1:
                    a = calc(tmpX*3 + tmpY%3, now)
                    b = calc(tmpX*3 + tmpY%3 + 1, now)
                    queue.append((tmpX, tmpY, merge(a,b)))
    cnt += 1
if flag:
    print(-1)
else:
    print(cnt)