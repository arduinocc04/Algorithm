import sys
input = sys.stdin.readline
n,m = map(int, input().split())
p = [i for i in range(n+1)]
def getParent(n):
    if n == p[n]:  return n
    p[n] = getParent(p[n])
    return p[n]
def union(n1,n2):
    global p
    p1 = getParent(n1)
    p2 = getParent(n2)
    if p1 > p2:
        p[p1] = p2
    else:
        p[p2] = p1
def isInSameSet(n1,n2):
    return getParent(n1) == getParent(n2)
for _ in range(m):
    c,a,b = map(int, input().split())
    if c == 0:
        union(a,b)
    else:
        sys.stdout.write('YES\n' if isInSameSet(a,b) else 'NO\n')