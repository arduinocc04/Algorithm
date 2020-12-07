import sys, math

input = sys.stdin.readline
def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])
def monotonechain(dots):
    dots.sort(key=lambda x:(x[0],x[1]))
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

def getDist(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def getDistDotvsSeg(seg, dot):
    x1MinusX2 = seg[0][0] - seg[1][0]
    y1MinusY2 = seg[0][1] - seg[1][1]
    if x1MinusX2 != 0:
        a = y1MinusY2/x1MinusX2
        b = seg[0][0]*a -seg[0][1]
        return abs(dot[1] - a*dot[0] + b)/math.sqrt(a**2 + 1)
    else:
        return abs(seg[0][0] - dot[0])

while True:
    try:
        n = int(input())
    except EOFError:
        break
    dots = [[int(i) for i in input().split()] for _ in range(n)]

    convexHull = monotonechain(dots)
    max_ = 0
    for i in range(len(convexHull)):
        for j in range(i+1, len(convexHull)):
            if (tmp:= getDist(convexHull[i], convexHull[j])) > max_:
                max_ = tmp
                maxIn1 = i
                maxIn2 = j
    print(f'{max_=}')
    max2 = 0
    for i in range(len(convexHull)):
        if (tmp:= getDistDotvsSeg([convexHull[maxIn1], convexHull[maxIn2]], convexHull[i])) > max2:
            max2 = tmp
    print(f'{max2=}')
    print(2*(max_ + max2))