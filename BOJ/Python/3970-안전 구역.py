import sys
import math

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    dots.sort(key=lambda x:(x[0],x[1]))
    if len(dots) <=1:
        return dots

    lower = []
    for d in dots:
        while len(lower) >= 2 and ccw((lower[-2][0], lower[-2][1]), (lower[-1][0], lower[-1][1]), (d[0], d[1])) <= 0:
            lower.pop()
        lower.append(d)

    upper = []
    for d in reversed(dots):
        while len(upper) >= 2 and ccw((upper[-2][0], upper[-2][1]), (upper[-1][0], upper[-1][1]), (d[0], d[1])) <= 0:
            upper.pop()
        upper.append(d)
    return lower[:-1] + upper[:-1]
def getDist(p1,p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    circles = [[int(i) for i in input().split()] for _ in range(n)]
    circles = monotonechain(circles)
    s = 0
    for i in range(len(circles)):
        s += getDist(circles[i-1], circles[i])