import sys
input = sys.stdin.readline

def find(n):
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]

def union(n1,n2):
    n1 = find(n1)
    n2 = find(n2)
    if n1 < n2:
        p[n2] = n1
    else:
        p[n1] = n2

def isInSameSet(n1,n2):
    return find(n1) == find(n2)

n,k = map(int, input().split())
graph = [[int(i) for i in input().split()] for _ in range(k)]
p = [int(i) for i in range(n)]

graph.sort(key=lambda x:x[2])
mst = []
s = 0
i = 0
mA = mst.append
while len(mst) < n-1:
    a,b,w = graph[i]
    if not isInSameSet(a,b):
        union(a,b)
        s += w
        mA(graph[i])
    i += 1
print(s)
print(s-mst[0][2])