import sys
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

for _ in range(int(input())):
    n = int(input())
    nerds = []
    nNerds = []
    nA = nerds.append
    nNA = nNerds.append
    for i in range(n):
        flag, x, y = map(int, input().split())
        if flag:
            nA([x,y])
        else:
            nNA([x,y])
    nerds = monotonechain(nerds)
    nNerds = monotonechain(nNerds)