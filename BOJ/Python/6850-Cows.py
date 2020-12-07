import sys
input = sys.stdin.readline

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    dots.sort(key=lambda x:(x[0],x[1]))
    if len(dots) <=1:
        return dots

    lower = []
    for i in range(len(dots)):
        while (len(lower) >= 2 and ccw(dots[lower[-2]], dots[lower[-1]], dots[i]) <= 0):
            if len(lower) == 0:  return None
            lower.pop()
        lower.append(i)

    upper = []
    for i in range(len(dots)):
        while (len(upper) >= 2 and ccw(dots[upper[-2]], dots[upper[-1]], dots[n-1-i]) <= 0):
            upper.pop()
        upper.append(n-1-i)

    for i in range(len(lower)):
        lower[i] = dots[lower[i]]

    for i in range(len(upper)):
        upper[i] = dots[upper[i]]
    return lower[:-1] + upper[:-1]

def getDoubledAreaOfTriangle(d1, d2, d3):
    x1,y1 = d1
    x2,y2 = d2
    x3,y3 = d3
    return ((x1*y2 + x2*y3 + x3*y1) - (x1*y3 + x3*y2 + x2*y1))

n = int(input())
dots = [[int(i) for i in input().split()] for _ in range(n)]
dots = monotonechain(dots)
s = 0
for i in range(len(dots)-1):
    s += getDoubledAreaOfTriangle(dots[0], dots[i], dots[i+1])
print(int(s/100))