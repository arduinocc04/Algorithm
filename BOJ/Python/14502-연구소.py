from collections import deque
import sys
from copy import deepcopy
input = sys.stdin.readline
n,m = map(int, input().split())
originalMap = [[int(i) for i in input().split()] for _ in range(n)]
empties = []
viruses = []
for y in range(n):
    for x in range(m):
        if originalMap[y][x] == 0:
            empties.append((x,y))
        if originalMap[y][x] == 2:
            viruses.append((x,y))
max_ = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
def getCount(array):
    s = 0
    for i in array:
        s += i.count(0)
    return s

for i in range(len(empties)):
    for j in range(i+1, len(empties)):
        for k in range(j+1, len(empties)):
            nowMap = deepcopy(originalMap)
            nowMap[empties[i][1]][empties[i][0]] = 1
            nowMap[empties[j][1]][empties[j][0]] = 1
            nowMap[empties[k][1]][empties[k][0]] = 1
            queue = deque(viruses)
            while queue:
                x,y = queue.popleft()
                for i in range(4):
                    tmpX = x + dx[i]
                    tmpY = y + dy[i]
                    if 0 <= tmpX <= m-1 and 0 <= tmpY <= n-1 and nowMap[tmpY][tmpX] == 0:
                        nowMap[tmpY][tmpX] = 2
                        queue.append((tmpX, tmpY))
            max_ = max(max_, getCount(nowMap))
print(max_)