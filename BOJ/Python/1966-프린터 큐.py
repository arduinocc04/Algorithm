import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
    n,m = map(int, input().split())
    queue = deque([[int(i),False] for i in input().split()])
    queue[m][1] = True
    j = 1
    while True:
        flag = True
        for i in range(len(queue)):
            if queue[i][0] > queue[0][0]:
                flag = False
                break
        if flag:
            if queue.popleft()[1]:
                print(j)
                break
            j += 1
        else:
            queue.append(queue.popleft())