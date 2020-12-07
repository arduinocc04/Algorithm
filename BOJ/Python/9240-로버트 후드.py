import sys, math
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
c = int(input())
dots = [[int(i) for i in input().split()] for _ in range(c)]
dots = monotonechain(dots)
max_ = 0
for i in range(len(dots)):
    for j in range(i+1, len(dots)):
        if (tmp:=(dots[i][0] - dots[j][0])**2 + (dots[i][1] - dots[j][1])**2) > max_:
            max_ = tmp
print(math.sqrt(max_))