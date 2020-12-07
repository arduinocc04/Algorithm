import sys
import math

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

def getDist(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def round(n:float, m) -> float:
    return math.floor(n*(10**m)+0.5)/(10**m)

input = sys.stdin.readline

n = int(input())
dots = [[int(i) for i in input().split()] for _ in range(n)]
dots = monotonechain(dots)
s = 0
for i in range(len(dots)):
    s += getDist(dots[i-1], dots[i])
print(round(s, 2))