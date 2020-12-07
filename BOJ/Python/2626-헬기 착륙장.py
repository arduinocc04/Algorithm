import sys
import math

input = sys.stdin.readline
n = int(input())
dots = [[int(i) for i in input().split()] for _ in range(n)]

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

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

def getDistSquared(d1, d2):
    return (d1[0] - d2[0])**2 + (d1[1] - d2[1])**2

def calc(d1,d2,d3):
    return getDistSquared(d1, d2) + getDistSquared(d2, d3) + getDistSquared(d1, d3)

def round(n:float) ->float:
    return math.floor(n*(10**3)+0.5)/(10**3)
"""
if n>2:
    important = monotonechain(dots)
    maxIn1 = 0
    maxIn2 = 1
    maxIn3 = 2
    maxVal = calc(important[0],important[1], important[2])
    for i in range(len(important)):
        for j in range(i+1, len(important)):
            for k in range(j+1, len(important)):
                if (tmp:= calc(important[i], important[j], important[k])) > maxVal:
                    maxVal = tmp
                    maxIn1 = i
                    maxIn2 = j
                    maxIn3 = k
    x1,y1 = important[maxIn1]
    x2,y2 = important[maxIn2]
    x3,y3 = important[maxIn3]
    x = ((x2**2 - x3**2 + y2**2 - y3**2)*(y1 - y2) - (x2**2 - x1**2 + y2**2 - y1**2))/(2*(x1-x2)*(y3-y2) - 2*(x3-x2)*(y1-y2))
    y = ((y2**2 - y3**2 + x2**2 - x3**2)*(x1-x2) - (y2**2 - y1**2 + x2**2 - x1**2)*(x3 - x2))/(2*(y1-y2)*(x3-x2) - 2*(y3-y2)*(x1-x2))
    print(f'{x} {y}')
    print(math.sqrt(getDistSquared([x,y], important[maxIn1])))
"""

important = monotonechain(dots)
xSum = 0
ySum = 0
for i in range(n):
    xSum += dots[i][0]
    ySum += dots[i][1]
x = xSum/n
y = ySum/n
ratio = 0.1
for _ in range(10000):
    maxIn = 0
    maxVal = (x - important[0][0])**2 + (y - important[0][1])**2
    for i in range(len(important)):
        if (tmp:= (x - important[i][0])**2 + (y - important[i][1])**2) > maxVal:
            maxVal = tmp
            maxIn = i
    x += (important[maxIn][0] - x)*ratio
    y += (important[maxIn][1] - y)*ratio
    ratio *= 0.999
print(f'{round(x)} {round(y)}')
print(round(math.sqrt(maxVal)))