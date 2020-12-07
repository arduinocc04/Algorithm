import sys

input = sys.stdin.readline

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    dots.sort()
    if len(dots) <=1:
        return dots

    lower = []
    for d in dots:
        while len(lower) >= 2 and ccw(lower[-2], lower[-1], d) <= 0:
            lower.pop()
        lower.append(d)

    upper = []
    for d in reversed(dots):
        while len(upper) >= 2 and ccw(upper[-2], upper[-1], d) <= 0:
            upper.pop()
        upper.append(d)
    return lower[:-1] + upper[:-1]

def cccw(p1, p2, p3, p4):
    tmp = p4[:]
    tmp[0] -= (p3[0] - p2[0])
    tmp[1] -= (p3[1] - p2[1])
    return ccw(p1, p2, tmp)


def ternarySearch(start,end, flag):
    if flag:
        lo = start+1
        hi = end-1
    else:
        lo = end+1
        hi = start-1 + N
    while hi-lo >= 3:
        p = (lo*2 + hi)//3
        q = (hi*2 + lo)//3
        if getArea(convexHull[start], convexHull[end], convexHull[p%N]) > getArea(convexHull[start], convexHull[end], convexHull[q%N]):
            hi = q
        else:
            lo = p
    max_ = 0
    for i in range(lo, hi+1):
        max_ = max(max_, getArea(convexHull[start], convexHull[end], convexHull[i%N]))
    return max_

def getArea(p1,p2,p3):
    ans = abs(ccw(p1, p2, p3))
    if ans/2 != ans//2:
        return ans//2 + 0.5
    else:
        return ans//2

for _ in range(int(input())):
    n = int(input())
    dots = [[int(i) for i in input().split()] for j in range(n)]
    convexHull = monotonechain(dots)
    N = len(convexHull)

    if N == 3:
        print(getArea(convexHull[0], convexHull[1], convexHull[2]))
    else:
        ans = 0
        """
        j = 1
        for i in range(N):
            ans = max(ans, ternarySearch(i%N, j%N, True) + ternarySearch(i%N, j%N, False))
            while j+1 != i and cccw(convexHull[i], convexHull[(i+1)%N], convexHull[j%N], convexHull[(j+1)%N]) > 0:
                j += 1
        """
        for i in range(N):
            for j in range(i+1, N):
                ans = max(ans, ternarySearch(i, j, True) + ternarySearch(i, j, False))
        
        print(ans)