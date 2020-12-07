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

def getDist(p1,p2):
    return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2

def dfs(n, p):
    if n in p: return
    for i in graph[n]:
        union(n, i)
        dfs(i, p+[n])


for _ in range(int(input())):
    n = int(input())
    p = [i for i in range(n)]
    a = [[int(i) for i in input().split()]for j in range(n)]
    graph = [[] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if getDist(a[i][:2], a[j][:2]) <= (a[i][-1] + a[j][-1])**2:
                graph[i].append(j)
                graph[j].append(i)
    for i in range(n):
        dfs(i, [])
    b = [False]*n
    for i in p:
        b[i] = True
    print(b.count(True))