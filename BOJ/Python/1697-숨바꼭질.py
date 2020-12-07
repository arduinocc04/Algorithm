n,m = map(int, input().split())

queue = []
queue.append([n, 0])
visited = [False]*100000
visited[n-1] = True
flag = True
if n > m:
    print(n-m)
    flag = False
prev = 0
i = 0
while flag:
    a = len(queue) -prev
    prev = len(queue)
    for _ in range(a):
        x, count = queue[i]
        # print(f'{queue=}')
        i += 1
        if(x == m):
            print(count)
            flag = False
            break
        if x < 100000 and not visited[x]:
            queue.append([x+1, count+1])
            visited[x] = True
        if x > 1 and not visited[x-2]:
            queue.append([x-1, count+1])
            visited[x-2] = True
        if x <= 50000 and not visited[2*x - 1]:
            queue.append([2*x, count+1])
            visited[2*x-1] = True