import sys
from collections import deque
input = sys.stdin.readline
for _ in range(int(input())):
    v,e = map(int, input().split())
    map_ = {}
    for i in range(e):
        a,b = map(int, input().split())
        if a in map_:
            map_[a].append(b)
        else:
            map_[a] = [b]
        if b in map_:
            map_[b].append(a)
        else:
            map_[b] = [a]

    queue = deque()
    for i in map_[a]:
        queue.append(i)
    while len(queue):
        a = queue.popleft()
        if a in map_:
            for i in map_[a]:
                queue.append(i)
            del map_[a]
    if len(map_):
        print("YES")
    else:
        print('NO')
