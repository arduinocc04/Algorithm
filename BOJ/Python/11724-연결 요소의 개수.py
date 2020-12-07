import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int, input().split())
map_ = dict()
set_ = set([i+1 for i in range(n)])
for _ in range(m):
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
cnt = 0
while map_:
    a,b = map_.popitem()
    for i in b:
        queue.append(i)
    while queue:
        a = queue.popleft()
        if a in map_:
            for i in map_[a]:
                queue.append(i)
            del map_[a]
        if a in set_:
            set_.remove(a)
    cnt += 1
print(cnt + len(set_))