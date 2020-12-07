from collections import deque

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

for _ in range(int(input())):
    n = int(input())
    start = [int(i) for i in input().split()]
    finish = [int(i) for i in input().split()]
    queue = deque()
    visited = [[False]*n for i in range(n)]
    queue.append(tuple(start))
    flag = True
    cnt = 0
    while flag:
        for _ in range(len(queue)):
            x,y = queue.popleft()
            if x == finish[0] and y == finish[1]:
                flag = False
                break
            for i in range(len(dx)):
                tmpX = x + dx[i]
                tmpY = y + dy[i]
                if 0 <= tmpX <= n-1 and 0<= tmpY <= n-1 and not visited[tmpX][tmpY]:
                    visited[tmpX][tmpY] = True
                    queue.append((tmpX, tmpY))
        cnt += 1
    print(cnt-1)