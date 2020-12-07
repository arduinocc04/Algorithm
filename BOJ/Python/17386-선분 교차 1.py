x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def compare(n1, n2):
    return n1[1] < n2[1] if n1[0] == n2[0] else n1[0] < n2[0]

def segVsSeg(a,b,c,d):
    ab = ccw(a, b, c) * ccw(a, b, d)
    cd = ccw(c, d, a) * ccw(c, d, b)
    if ab == cd == 0:
        if compare(b,a): tmp = b; b = a; a = tmp;
        if compare(d,c): tmp = c; c = d; d = tmp;
        return not (compare(b,c) or compare(d,a))
    return ab <= 0 and cd <= 0

print(int(segVsSeg([x1,y1], [x2,y2], [x3,y3], [x4,y4])))