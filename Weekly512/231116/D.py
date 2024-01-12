from collections import deque
n = int(input())
q = deque()

maxLen = -1
lastSt = 987654321
for _ in range(n):
    a = input().split()
    if a[0] == '1':
        q.append(int(a[1]))
    else:
        q.popleft()
    if len(q) >= maxLen:
        if len(q) == maxLen: lastSt = min(q[-1], lastSt)
        else: lastSt = q[-1]
        maxLen = len(q)
print(maxLen, lastSt)
