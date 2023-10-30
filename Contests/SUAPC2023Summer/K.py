rect1 = [[int(i) for i in input().split()] for _ in range(4)]
rect2 = [[int(i) for i in input().split()] for _ in range(4)]

cent1x4 = [0, 0]
cent2x4 = [0, 0]

for i in range(4):
    for j in range(2):
        cent1x4[j] += rect1[i][j]
        cent2x4[j] += rect2[i][j]

slopeUp = cent2x4[1] - cent1x4[1]
slopeDn = cent2x4[0] - cent1x4[0]


slope = [slopeUp, slopeDn]

def mul(a, b):
    return [a[0]*b[0], a[1]*b[1]]

def minus(a):
    return [-a[0], a[1]]

def ssum(a, b):
    return [a[0]*b[1] + a[1]*b[0], a[1]*b[1]]

def gcd(a, b):
    a = abs(a)
    b = abs(b)
    while b:
        tmp = a % b
        a = b
        b = tmp

    return a

x = [cent1x4[0], 4]
y = [cent1x4[1], 4]
def compact(a):
    t = gcd(a[0], a[1])
    return [a[0]//t, a[1]//t]

p = compact(slope)
# print(x, y, p, mul(p, x), minus(mul(p, x)))
q = compact(ssum(y, minus(mul(p, x))))

if p[1]*p[0] < 0:
    p[1] = abs(p[1])
    p[0] = -abs(p[0])
else:
    p[1] = abs(p[1])
    p[0] = abs(p[0])

if q[1]*q[0] < 0:
    q[1] = abs(q[1])
    q[0] = -abs(q[0])
else:
    q[1] = abs(q[1])
    q[0] = abs(q[0])

if p[1] == 1 or p[0] == 0:
    print(p[0], end=' ')
else:
    print(f"{p[0]}/{p[1]}", end=' ')

if q[1] == 1 or p[0] == 0:
    print(q[0])
else:
    print(f"{q[0]}/{q[1]}", end=' ')