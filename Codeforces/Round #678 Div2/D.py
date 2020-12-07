n = int(input())
#b = [int(i) for i in input().split()]

graph = [[] for _ in range(n)]
j = 0
for i in input().split():
    j += 1
    graph[j].append(int(i)-1)
    graph[int(i)-1].append(j)


p = [i for i in range(n)]
a = [int(i) for i in input().split()]
"""
def find(n):
    global p
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]

def union(p1,p2):
    global p, a
    p1 = find(p1)
    p2 = find(p2)
    if p1 < p2:
        p[p2] = p1
        a[p1] += a[p2]
    else:
        p[p1] = p2
        a[p2] += a[p1]
"""
b = 0
def dfs(n, p):
    global b
    if len(graph[n]) == 1:
        b += 1
        return
    for i in graph[n]:
        if i == p: continue
        dfs(i, n)
dfs(0,-1)
#print(a[0]//len(graph[0]) + int(a[0]%len(graph[0]) != 0))

tmp = sum(a)
print(tmp//b + int(tmp%b != 0))