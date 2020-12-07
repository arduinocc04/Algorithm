def calc(i):
    global visited
    if not visited[i]:
        visited[i] = True
        for a in linked[i]:
            calc(a-1)
    return 0


coumputerCount = int(input())
connectionCount = int(input())
linked = []
for i in range(coumputerCount):
    linked.append([])
for i in range(connectionCount):
    com1Num,com2Num = map(int, input().split())
    linked[com1Num-1].append(com2Num)
    linked[com2Num-1].append(com1Num)

if connectionCount:
    visited = [False]*coumputerCount
    calc(0)
    visited[0] = False
    print(visited.count(True))
else:
    print(0)