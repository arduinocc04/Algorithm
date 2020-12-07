import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

# 다익스트라 알고리즘
def solve(graph, K):
    dist = [INF] * (len(graph) + 1)
    dist[K] = 0

    priority_queue = []
    heapq.heappush(priority_queue, [0, K])

    while priority_queue:
        current_dist, here = heapq.heappop(priority_queue)

        for there, length in graph[here].items():
            next_dist = dist[here] + length

            if next_dist < dist[there]:
                dist[there] = next_dist
                heapq.heappush(priority_queue, [next_dist, there])

    return dist

if __name__ == "__main__":
    V, E = map(int, input().split())
    K = int(input())
    graph = [dict() for _ in range(V)]

    for _ in range(E):
        u, v, w = map(int, input().split())
        if v-1 in graph[u-1]:
            graph[u-1][v-1] = min(graph[u-1][v-1], w)
        else:
            graph[u-1][v-1] = w

    dist = solve(graph, K-1)

    for d in dist[:-1]:
        print(d if d != INF else "INF")