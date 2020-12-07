import heapq
n,k = map(int, input().split())
pq = []
visited = [False]*150001
heapq.heappush(pq, (0,n))
while len(pq):
    a,cnt = heapq.heappop(pq)
    if a == k:
        print(cnt)
        break
    if a > 0 and not visited[a-1]:
        heapq.heappush(pq, (cnt+1, a-1))
        visited[a-1] = True
    if a < 150000 and not visited[a+1]:
        heapq.heappush(pq, (cnt+1, a+1))
        visited[a+1] = True
    if 0 <= 2*a <= 150000 and not visited[2*a]:
        heapq.heappush(pq, (cnt, 2*a))
        visited[2*a] = True