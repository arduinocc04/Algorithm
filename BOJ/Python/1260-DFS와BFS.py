import sys
sys.setrecursionlimit(100000000) 
def dfs(num):
    global visited, result
    if visited[num-1]:
        return
    visited[num-1] = True
    result.append(num)
    for n in edges[num-1]:
        dfs(n)

def bfs(num):
    global visited, result
    queue = []
    queue.append(num)
    visited[num-1] = True
    while len(queue):
        a = len(queue)
        for _ in range(a):
            n = queue.pop(0)
            result.append(n)
            for i in edges[n-1]:
                if not visited[i-1]:
                    queue.append(i)
                    visited[i-1] = True

nodeCount, edgeCount, startNum = map(int, input().split())
edges = []
for _ in range(edgeCount):
    edges.append([])
for _ in range(edgeCount):
    a,b = map(int, sys.stdin.readline().split())
    edges[b-1].append(a)
    edges[a-1].append(b)
for i in range(len(edges)):
    edges[i].sort()

visited = [False]*edgeCount
result= []
dfs(startNum)
for n in result:
    sys.stdout.write(str(n) + ' ')
print()

visited = [False]*edgeCount
result = []
bfs(startNum)
for n in result:
    sys.stdout.write(str(n) + ' ')
print()