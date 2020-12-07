import sys
input = sys.stdin.readline

v,e = map(int, input().split())
edges = []
eA = edges.append
for _ in range(e):
    u,a,w = map(int, input().split())
    eA([u-1, a-1, w])
edges.sort(key = lambda x: x[2])
p = [i for i in range(v)]

def find(n):
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]

def union(n1,n2):
    n1 = find(n1)
    n2 = find(n2)
    if n1 > n2:
        p[n1] = n2
    else:
        p[n2] = n1

def isInSameSet(n1,n2):
    return find(n1) == find(n2)

def getMst(notUse):
    global p
    cnt = 0
    i = 0
    s = 0
    while cnt < v - 1:
        if i== notUse:  i += 1
        u,a,w = edges[i]
        if not isInSameSet(u,a):
            union(u,a)
            s += w
            cnt += 1
        i += 1
    return s

mst = []
cnt = 0
i = 0
while cnt < v-1:
    u,a,w = edges[i]
    if not isInSameSet(u,a):
        union(u,a)
        mst.append(i)
        cnt += 1
    i += 1

min_ = 123131122322323
for i in mst:
    min_ = min(min_, getMst(i))
print(min_)