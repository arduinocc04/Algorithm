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

def isDotInPoly(dots, dot):
    if len(dots) <3: return False
    prev = ccw(dot, dots[0], dots[1])
    for i in range(len(dots)-2):
        if prev * ccw(dot, dots[i+1], dots[i+2]) < 0:
            return False
        prev = ccw(dot, dots[i+1], dots[i+2])
    return True

def segVsSeg(a,b,c,d):
    ab = ccw(a, b, c) * ccw(a, b, d)
    cd = ccw(c, d, a) * ccw(c, d, b)
    if ab == 0 and cd == 0:
        a = a[0]
        b = b[0]
        c = c[0]
        d = d[0]
        if b < a: tmp = b; b = a; a = tmp;
        if d < c: tmp = c; c = d; d = tmp;
        return not (b < c or d < a)
    return ab <= 0 and cd <= 0


def check(dots1, dots2):
    if len(dots1) < 1 or len(dots2) < 1:
        return False
    if(isDotInPoly(dots1, dots2[0]) or isDotInPoly(dots2, dots1[0])): return True
    for i in range(len(dots1)):
        for j in range(len(dots2)):
            if segVsSeg(dots1[i-1], dots1[i], dots2[j-1], dots2[j]):
                return True
    return False

for _ in range(int(input())):
    n,m = map(int, input().split())
    blacks = [[int(i) for i in input().split()] for j in range(n)]
    whites = [[int(i) for i in input().split()] for j in range(m)]
    blacks = monotonechain(blacks)
    whites = monotonechain(whites)
    flag = False
    if m > 2:
        for i in range(len(blacks)):
            if isDotInPoly(whites, blacks[i]):
                flag = True
                break
    elif m == 1:
        for i in range(len(blacks)-1):
            if ccw(blacks[i], blacks[i+1], whites[0]) == 0:
                flag = True
                break
    if not flag:
        if n > 2:
            for i in range(len(whites)):
                if isDotInPoly(blacks, whites[i]):
                    flag = True
                    break
        elif n == 1:
            for i in range(len(whites)-1):
                if ccw(whites[i], whites[i+1], blacks[0]) == 0:
                    flag = True
                    break
    if check(blacks, whites):
        flag = True
    if flag:  print('NO')
    else:  print('YES')