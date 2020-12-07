import sys
def sumCoordinate(dot1, dot2):
    return(dot1[0]+dot2[0], dot1[1]+dot2[1])

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

input = sys.stdin.readline

n,m = map(int, input().split())
aDots = [[int(i) for i in input().split()] for _ in range(n)]
bDots = [[int(i) for i in input().split()] for _ in range(m)]
dots = []
dA = dots.append
for aDot in aDots:
    for bDot in bDots:
        dA(sumCoordinate(aDot, bDot))
res = monotonechain(dots)
print(len(res))
for x,y in res:
    print(f'{x} {y}')