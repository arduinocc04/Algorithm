import sys
import heapq
input = sys.stdin.readline
n = int(input())
query = [input() for _ in range(2*n)]
avail = [True]*(n+3)
flag = True
ans = []
pq = []
flag2 = False
prev = 13123123123
for q in reversed(query):
    if q[0] == '-':
        a = int(q[2:])
        if flag2 and prev < a:
            flag = False
            break
        heapq.heappush(pq, a)
        avail[a] = False
        flag2 = True
        prev = a
    else:
        flag2 = False
        if pq:
            ans.append(heapq.heappop(pq))
        else:
            flag = False
            break

if flag:
    print("YES")
    print(*list(reversed(ans)))
else:
    print('NO')