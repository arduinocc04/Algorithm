import sys

input = sys.stdin.readline
def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def cccw(p1, p2, p3, p4):
    tmp = p4[:]
    tmp[0] -= (p3[0] - p2[0])
    tmp[1] -= (p3[1] - p2[1])
    return ccw(p1, p2, tmp)

def monotonechain(dots):
    dots.sort(key=lambda x:(x[0],x[1]))
    if len(dots) <=2:
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

def getSquaredDist(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def getDist(y):
    dots = [[stars[i][0] + d[i][0]*y, stars[i][1] + d[i][1]*y] for i in range(n)]
    convexHull = monotonechain(dots)
    N = len(convexHull)
    maxDist = 0
    j = 1
    maxDot1 = convexHull[0]
    maxDot2 = convexHull[1]
    for i in range(N):
        while j+1 != i and cccw(convexHull[i], convexHull[(i+1)%N], convexHull[j%N], convexHull[(j+1)%N]) > 0:
            if getSquaredDist(convexHull[i], convexHull[j%N]) > maxDist:
                maxDot1 = convexHull[i]
                maxDot2 = convexHull[j%N]
                maxDist = getSquaredDist(convexHull[i], convexHull[j%N])
            j += 1

        if getSquaredDist(convexHull[i], convexHull[j%N]) > maxDist:
            maxDot1 = convexHull[i]
            maxDot2 = convexHull[j%N]
            maxDist = getSquaredDist(convexHull[i], convexHull[j%N])
    return maxDist
    
n, t = map(int, input().split())
stars = []
d = []
sA = stars.append
dA = d.append
for i in range(n):
	x, y, dx, dy = map(int, input().split())
	sA([x,y])
	dA([dx, dy])
lo = 0
hi = t

while hi - lo >= 3:
	p = (2*lo + hi)//3
	q = (lo + 2*hi)//3
	if getDist(p) <= getDist(q):
		hi = q
	else:
		lo = p
result = getDist(lo)
minIn = lo
for i in range(lo, hi+1):
	if result > getDist(i):
		result = getDist(i)
		minIn = i
print(minIn)
print(result)