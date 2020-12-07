import sys
import math
input = sys.stdin.readline
n = int(input())
dots = [[float(i) for i in input().split()] for _ in range(n)]
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

if n > 1:
    important = monotonechain(dots)
    xSum = 0
    ySum = 0
    for i in range(n):
        xSum += dots[i][0]
        ySum += dots[i][1]
    x = xSum/n
    y = ySum/n
    ratio = 0.1
    for _ in range(30000):
        maxIn = 0
        maxVal = (x - important[0][0])**2 + (y - important[0][1])
        for i in range(len(important)):
            if (tmp:= (x - important[i][0])**2 + (y - important[i][1])**2) > maxVal:
                maxVal = tmp
                maxIn = i
        x += (important[maxIn][0] - x)*ratio
        y += (important[maxIn][1] - y)*ratio
        ratio *= 0.999
    print(f'{x} {y} {math.sqrt((x - important[maxIn][0])**2 + (y - important[maxIn][1])**2)}')
else:
    print(f'{dots[0][0]} {dots[0][1]} 0')