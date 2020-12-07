import sys
import math
input = sys.stdin.readline

n = int(input())
dots = []
d = []
doA = dots.append
dA = d.append
for _ in range(n):
    x,y,dx,dy = map(int, input().split())
    doA([x,y])
    dA([dx,dy])

def getDoubledDist(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def getMaxDist(t):
    dos = [[dots[i][0] + t*d[i][0], dots[i][1] + t*d[i][1]] for i in range(n)]
    ans = -12
    for i in range(n):
        for j in range(i+1, n):
            ans = max(ans, getDoubledDist(dos[i], dos[j]))
    return ans


lo = 0
hi = 1000000
while hi - lo >= 3:
    p = (lo*2 + hi)//3
    q = (hi*2 + lo)//3
    if getMaxDist(p) > getMaxDist(q):
        lo = p
    else:
        hi = q
ans = -12
for i in range(lo, hi+1):
    ans = max(ans, getMaxDist(i))
print(math.sqrt(ans/2))