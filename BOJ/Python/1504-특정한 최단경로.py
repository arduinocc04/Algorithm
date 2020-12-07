import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

n,e = map(int, input().split())
graph = [[INF]*n for _ in range(n)]
for _ in range(e):
    a,b,c = map(int, input().split())
    graph[a-1][b-1] = c
    graph[b-1][a-1] = c

must1,must2 = map(int, input().split())

def dajikstra():
    global n
    dist = [INF]*n
    pq = [(0,0)]
    dist[0] = 0
    visited = [False]*n
    while len(pq):
        dist1,n = heapq.heappop(pq)
        if visited[n]:    continue
        visited[n] = True
        for i in range(len(graph[n])):
            if visited[i]:    continue
            if dist[i] > graph[n][i] + dist1:
                dist[i] = graph[n][i] + dist1
                heapq.heappush(pq, (dist[i], i))
    return dist

for i in dajikstra():
    print(i if i != INF else 'INF')