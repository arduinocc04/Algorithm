import sys
import math
input = sys.stdin.readline

def getSquaredDist(p1,p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def getDistLineVsDot(p1, l1, l2):
    x = l1[0] - l2[0]
    flag = True
    if x != 0:
        a = (l1[1] - l2[1])/x
    else:
        flag = False
    if flag:
        return abs(p1[1] - a*p1[0] - (l1[1] - a*l1[0]))/math.sqrt(a**2 + 1)
    else:
        return abs(l1[0] - p1[0])

def getPerpendicularLine(ol1, ol2, p1):
    y = ol1[1] - ol2[1]
    flag = True
    if y != 0:
        a = -(ol1[0] - ol2[0])/y
    else:
        flag = False
    if flag:
        if a != 0:
            tmp = ((1/a)*ol1[0] + a*p1[0] + p1[1] - ol1[1])/(a + 1/a)
            return (tmp, + tmp/a - 1/ol1[0] + ol1[1])
        else:
            return (ol1[0], p1[1])
    else:
        return (p1[0], ol1[1])
        

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

while True:
    n = int(input())
    if n == 0: break
    dots = monotonechain([[int(i) for i in input().split()] for _ in range(n)])
    ratio = 0.1
    x,y = 0, 0
    for i in range(len(dots)):
        x += dots[i][0]
        y += dots[i][1]
    x /= n
    y /= n
    minVal = 0
    for _ in range(10000):
        minIn = 0
        maxV = getDistLineVsDot([x,y], dots[0], dots[1])
        for i in range(n):
            if (tmp := getDistLineVsDot([x,y], dots[i-1], dots[i])) > maxV:
                maxV = tmp
                minIn = i
        tmpX,tmpY = getPerpendicularLine(dots[minIn-1], dots[minIn], [x,y])
        x += (tmpX - x)*ratio
        y += (tmpY - y)*ratio
        ratio *= 0.999
    print(maxV)