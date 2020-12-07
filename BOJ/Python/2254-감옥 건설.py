import sys
input = sys.stdin.readline

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])
def monotonechain(dots):
    global used
    dots.sort(key=lambda x:(x[0],x[1]))
    if len(dots) <=1:
        return dots

    lower = []
    for i in range(len(dots)):
        if used[i]: continue
        while (len(lower) >= 2 and ccw(dots[lower[-2]], dots[lower[-1]], dots[i]) <= 0):
            if len(lower) == 0:  return None
            lower.pop()
        lower.append(i)

    upper = []
    for i in range(len(dots)):
        if used[n-1-i]: continue
        while (len(upper) >= 2 and ccw(dots[upper[-2]], dots[upper[-1]], dots[n-1-i]) <= 0):
            upper.pop()
        upper.append(n-1-i)

    for i in range(len(lower)):
        used[lower[i]] = True

    for i in range(len(upper)):
        used[upper[i]] = True
    return lower[:-1] + upper[:-1]


def isDotInPoly(dots, dot):
    prev = ccw(dot, dots[0], dots[1])
    for i in range(len(dots)-2):
        if prev * ccw(dot, dots[i+1], dots[i+2]) < 0:
            return False
        prev = ccw(dot, dots[i+1], dots[i+2])
    return True

n,px,py = map(int, input().split())
dots = [[int(i) for i in input().split()] for _ in range(n)]
used = [False]*n
cnt = 0
while True:
    wall = monotonechain(dots)
    if not wall:  break
    if not isDotInPoly([dots[i] for i in wall], [px,py]):
        break
    cnt += 1
print(cnt)