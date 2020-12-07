from collections import deque
d = int(input())
map_ = [[1,2], [0,2,3], [0,1,3,4], [1,2,4,5], [2,3,5], [3,4,6], [5,7], [4,6]]
queue = deque()
queue.append((map_[0], 0))
rCnt = 0
while queue:
    a,cnt = queue.popleft()
    if cnt == d:
        if len(a) == 2 and 1 in a:
            rCnt += 1
        continue
    for i in a:
        queue.append((map_[i], cnt+1))

print(rCnt%1000000007)