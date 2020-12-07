import sys
import math

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

def isDotInPoly(dots, dot):
    prev = ccw(dot, dots[0], dots[1])
    for i in range(len(dots)-2):
        if prev * ccw(dot, dots[i+1], dots[i+2]) < 0:
            return False
        prev = ccw(dot, dots[i+1], dots[i+2])
    return True

def segVsSeg(p1,p2):
    x1,y1 = p1[0]
    x2,y2 = p1[1]
    x3,y3 = p2[0]
    x4,y4 = p2[1]
    if min(x3, x4) <= max(x1,x2) and min(x1,x2) < max(x3,x4):
        if ccw([x1, y1], [x2,y2], [x3, y3])*ccw([x1, y1], [x2, y2], [x4, y4]) <= 0 and ccw([x3,y3], [x4, y4], [x1, y1]) * ccw([x3, y3], [x4, y4], [x2, y2]) <=0:
            return True
        else:
            return False
    else:
        return False

def check(dots, dot1, dot2):
    for i in range(len(dots)):
        if segVsSeg([dots[i-1], dots[i]], [dot1, dot2]):
            return True
    return False

def round(n:float) ->float:
    return math.floor(n*(10**3)+0.5)/(10**3)

for _ in range(int(input())):
    xl,yl = map(int, input().split())
    xe,ye = map(int, input().split())
    n = int(input())
    dots = [[int(i) for i in input().split()] for _ in range(n)]
    convexHull = monotonechain(dots)
    if isDotInPoly(convexHull, (xl,yl)) or isDotInPoly(convexHull, (xe,ye)) or check(convexHull, (xl,yl), (xe,ye)):
        flag = False
    else:
        flag = True
    if flag:
        print(round(math.sqrt((xl-xe)**2 + (yl-ye)**2)))
    else:
        print('IMPOSSIBLE')
    #아이디어: (xl,yl)과 (xe,ye)를 이은 선분이 dots의 convexhull과 만나거나 겹치는가?