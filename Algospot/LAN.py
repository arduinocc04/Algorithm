# LAN
import sys
import math
input = sys.stdin.readline

def getDist(n1,n2):
    return math.sqrt((n1[0] - n2[0])**2 + (n1[1]-n2[1])**2)
def find(n):
    global p
    if n == p[n]: return n
    p[n] = find(p[n])
    return p[n]

def union(n1,n2):
    global p
    n1 = find(n1)
    n2 = find(n2)
    if n1 < n2:
        p[n2] = n1
    else:
        p[n1] = n2

def isInSameSet(n1,n2):
    return find(n1) == find(n2)

for _ in range(int(input())):
    n,m = map(int, input().split())
    p = [i for i in range(n)]
    xs = [int(i) for i in input().split()]
    ys = [int(i) for i in input().split()]
    buildings = [[xs[i], ys[i]] for i in range(n)]
    edges = [[i, j, getDist(buildings[i], buildings[j])]for i in range(n) for j in range(i+1, n)]
    edges.sort(key= lambda x:x[2])
    cnt = m
    for i in range(m):
        a,b = map(int, input().split())
        if isInSameSet(a,b):  cnt -= 1
        else:
            union(a,b)
    i = 0
    s = 0
    while cnt < n-1:
        a,b,w = edges[i]
        if not isInSameSet(a,b):
            s += w
            cnt += 1
            union(a,b)
        i += 1
    print(s)