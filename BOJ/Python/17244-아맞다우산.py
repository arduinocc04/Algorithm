from collections import deque
n,m = map(int, input().split())
home = [[i for i in input()] for _ in range(m)]
start = None
things = []
for i in range(m):
    for j in range(n):
        if home[i][j] == 'S':
            start = i,j
            home[i][j] = '.'
        elif home[i][j] == 'X':
            things.append((i,j))
queue = deque()
visited = [[[False]*(2**5) for i in range(n)] for i in range(m)]
queue.append((start[0], start[1],0))
cnt = 0
flag = True
dx = [-1,1,0,0]
dy = [0,0,-1,1]
while flag:
    for _ in range(len(queue)):
        x,y,thing = queue.popleft()
        for i in range(4):
            tmpX = x + dx[i]
            tmpY = y + dy[i]
            if 0<= tmpX <= m-1 and 0<= tmpY <= n-1 and not visited[tmpX][tmpY][thing]:
                visited[tmpX][tmpY][thing] = True
                if home[tmpX][tmpY] == 'X':
                    queue.append((tmpX, tmpY, thing|(1<<things.index((tmpX,tmpY))) ))
                if home[tmpX][tmpY] == '.':
                    queue.append((tmpX, tmpY, thing))
                if home[tmpX][tmpY] == 'E' and thing == (2**len(things))-1:
                    flag = False
                    break
    cnt += 1
print(cnt)