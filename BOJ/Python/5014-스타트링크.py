from collections import deque
f,s,g,u,d = map(int, input().split())

queue = deque()
queue.append(s)
flag = True
visited = [False]*(f+1)
cnt = -1
while flag:
    if len(queue) == 0:
        print('use the stairs')
        break
    for _ in range(len(queue)):
        x = queue.popleft()
        if x == g:
            flag = False
            break
        if 1<=x-d and not visited[x-d]:
            queue.append(x-d)
            visited[x-d] = True
        if x+u <= f and not visited[x+u]:
            queue.append(x+u)
            visited[x+u] = True
    cnt += 1
if not flag:
    print(cnt)