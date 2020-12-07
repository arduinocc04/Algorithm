import sys
input = sys.stdin.readline

def getParent(node):
    if node == p[node]:  return node
    p[node] = getParent(p[node])
    return p[node]
def union(node1, node2):
    global p
    p1 = getParent(node1)
    p2 = getParent(node2)
    if p1 > p2:
        p[node1] = p2
    else:
        p[node2] = p1
def isInSameSet(node1,node2):
    return getParent(node1) == getParent(node2)

v,e = map(int, input().split())
eL = [[int(i) for i in input().split()] for _ in range(e)]
eL.sort(key=lambda x:x[2])
p = [i for i in range(v)]
cnt = 0
i = 0
s = 0
while cnt < v-1:
    a,b,c = eL[i]
    a,b = a-1,b-1
    i += 1
    if not isInSameSet(a,b):
        union(a,b)
        s += c
        cnt += 1
print(s)