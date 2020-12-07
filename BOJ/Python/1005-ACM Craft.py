import sys
from collections import deque
input = sys.stdin.readline
queue = deque()
for _ in range(int(input())):
    n,k = map(int, input().split())
    times = [int(i) for i in input().split()]
    tmp = [True]*n
    graph = [None]*n
    CNT = 0
    for i in range(k):
        a,b = map(int, input().split())
        if graph[a-1]:
            graph[a-1].append(b-1)
        else:
            graph[a-1] = [b-1]
        tmp[b-1] = False
    w = int(input())
    for i in graph:
        if i == None:  continue
        CNT += i.count(w-1)
    queue.clear()
    for i in range(len(tmp)):
        if tmp[i]:
            queue.append((i, times[i]))
    max_ = 0
    c = 0
    while True:
        if not len(queue) or CNT < c:   break
        x,t = queue.popleft()
        if x == w-1:
            if max_ < t:   max_ = t
            c += 1
            continue
        tmp = []
        if graph[x] == None:  continue
        for i in graph[x]:
            tmp.append(times[i])
        t += max(tmp)
        for j in graph[x]:
            queue.append((j,t))
    print(max_)