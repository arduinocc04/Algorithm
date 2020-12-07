from collections import deque
n = int(input())
map_ = []
for _ in range(n):
    map_.append([int(i) for i in input().split()])

queue = deque()
