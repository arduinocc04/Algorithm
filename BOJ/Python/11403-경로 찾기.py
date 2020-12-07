import sys
from collections import deque
input = sys.stdin.readline
n = int(input())
map_ = []
for _ in range(n):
    tmp = input().split()
    tmp2 = []
    for i in range(len(tmp)):
        if tmp[i] == '1':
            tmp2.append(i)
    map_.append(tmp2)

queue = deque()
res = []
for i in range(n):
    resTmp = []
    for j in range(n):
        queue.clear()
        flag = True
        visited = set()
        for k in map_[i]:
            queue.append(k)
        while flag:
            for _ in range(len(queue)):
                k = queue.popleft()
                if k == j:
                    resTmp.append(1)
                    flag = False
                    break
                elif k in visited:
                    pass
                else:
                    if k != j:
                        visited.add(k)
                    for l in map_[k]:
                        queue.append(l)
            
            if flag and len(queue) == 0:
                resTmp.append(0)
                flag = False
                break
    res.append(resTmp)
for i in res:
    for j in i:
        print(j, end=' ')
    print()