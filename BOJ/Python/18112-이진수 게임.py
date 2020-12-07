from collections import deque
l = int(input(),2)
k = int(input(),2)
queue = deque()
flag = True
cnt = -1
queue.append(l)
visited = [False]*(2**10)
while flag:
    for _ in range(len(queue)):
        x = queue.popleft()
        if x == k:
            flag = False
            break
        if x > 0 and not visited[x-1]:
            visited[x-1] = True
            queue.append(x-1)
        if x < 2**10 - 1 and not visited[x+1]:
            visited[x+1] = True
            queue.append(x+1)
        tmp = bin(x)[2:]
        for i in range(1, len(tmp)-1, 1):
            tmpX = int(tmp[:i] + str(int(tmp[i])^1) + tmp[i+1:], 2)
            if 0 <= tmpX <= 2**10 - 1 and not visited[tmpX]:
                visited[tmpX] = True
                queue.append(tmpX)
    cnt += 1
print(cnt)