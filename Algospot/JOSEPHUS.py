queue = []
for _ in range(int(input())):
    n,k = map(int, input().split())
    queue.clear()
    for i in range(n-1):
        queue.append(i+2)
    while(len(queue) != 2):
        for i in range(k-1):
            tmp = queue.pop(0)
            queue.append(tmp)
        queue.pop(0)
    print(*sorted(queue))