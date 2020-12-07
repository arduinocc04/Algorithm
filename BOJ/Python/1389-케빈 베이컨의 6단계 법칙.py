import sys
from collections import deque
input = sys.stdin.readline
n,m = map(int, input().split())
friends = []
for _ in range(n):
    friends.append(set())
for _ in range(m):
    a,b = map(int, input().split())
    friends[a-1].add(b-1)
    friends[b-1].add(a-1)
for i in range(len(friends)):
    friends[i] = list(friends[i])
min_ = 0
minVal = 122222121
queue = deque()
for i in range(n):
    sum_ = 0
    for j in range(n):
        flag = True
        queue.clear()
        for k in friends[i]:
            queue.append((k, 0))
        while flag:
            for _ in range(len(queue)):
                fs,cnt = queue.popleft()
                if fs == j:
                    flag = False
                    break
                else:
                    for k in friends[fs]:
                        queue.append((k,cnt+1))
        sum_ += cnt
    if sum_ < minVal:
        min_ = i
        minVal = sum_

print(min_+1)