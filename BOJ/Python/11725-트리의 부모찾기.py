from collections import deque
import sys
nodeCount = int(sys.stdin.readline())
tree = []
dict_ = dict()
for _ in range(nodeCount):
    a,b = map(int, sys.stdin.readline().split())
    if a in dict_:
        dict_[a].append(b)
    else:
        dict_[a] = [b]
    if b in dict_:
        dict_[b].append([b])
    else:
        dict_[b] = a

queue = deque()
for i in dict_[1]:
    queue.append(i)
    
while len(queue):
    a = len(queue)
    for _ in range(a):
        val = queue.popleft()
        tree.append(val)
        for i in dict_[val]:
            queue.append(i)