# ARCTIC-Kruskal's MST
import sys
import math

input = sys.stdin.readline

def getDist(n1,n2):
    return math.sqrt((n1[0] - n2[0])**2 + (n1[1] - n2[1])**2)

def find(n):
    global p
    if n == p[n]: return n
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

def round(n, digit):
    return int((n*(10**digit) + 0.5))/(10**digit)

for _ in range(int(input())):
    n = int(input())
    bases = [[float(i) for i in input().split()] for j in range(n)]
    edges = [[i, j, getDist(bases[i], bases[j])] for i in range(n) for j in range(i+1, n)]
    p = [i for i in range(n)]
    edges.sort(key = lambda x: x[2])
    cnt = 0
    i = 0
    while cnt != n-1:
        if not isInSameSet(edges[i][0], edges[i][1]):
            cnt += 1
            union(edges[i][0], edges[i][1])
        i += 1
    print("%.2f" % round(edges[i-1][2],2))