import sys

input = sys.stdin.readline
n = int(input())
dots = []
dA = dots.append
ndots = []
nDA = ndots.append
for _ in range(n):
    x,y,cmd = input().split()
    if cmd == 'I':
        dA([int(x), int(y)])
    else:
        nDA([int(x), int(y)])

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

def getDistSquared(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def getCircumCenter3(p1, p2, p3):
    """
    tmp = p2[0]**2 - p1[0]**2 + p2[1]**2 - p1[1]**2
    tmp2 = p2[0]**2 - p3[0]**2 + p2[1]**2 - p3[1]**2
    y3MY2 = p3[1] - p2[1]#y3MinusY2
    y1MY2 = p1[1] - p2[1]
    x1MX2 = p1[0] - p2[0]
    x3MX2 = p3[0] - p2[0]
    x = (tmp2*y1MY2 - tmp*y3MY2)/(2*x1MX2*y3MY2 - 2*x3MX2*y1MY2)
    y = (tmp2*x1MX2 - tmp*x3MX2)/(2*y1MY2*x3MX2 - 2*y3MY2*x1MX2)
    return x, y
    """
    a,b,c,d,e,f = p1[0],p1[1], p2[0], p2[1], p3[0], p3[1]
    if (c-a)*(f-d)==(e-c)*(d-b): return None
    A, B, C, D, E, F = 2*(c-a), 2*(d-b), 2*(e-c), 2*(f-d), c**2 - a**2 + d**2 - b**2, e**2 - c**2 + f**2 - d**2
    det = A*D-B*C
    x, y = (D*E-B*F)/det, (A*F-C*E)/det
    return x, y

def getMidPoint(p1, p2):
    return (p1[0] + p2[0])/2, (p1[1] + p2[1])/2

def main():
    importants = monotonechain(dots)
    for i in range(len(importants)):
        for j in range(i+1, len(importants)):
            for k in range(j+1, len(importants)):
                tmp = getCircumCenter3(importants[i], importants[j], importants[k])
                if tmp == None:  continue
                x,y = tmp
                rSquared = getDistSquared([x,y], importants[i])
                flag = True
                for l in range(len(importants)):
                    if getDistSquared([x,y], importants[l]) - rSquared > sys.float_info.epsilon:
                        flag = False
                        break
                if not flag:  continue
                
                for m in range(len(ndots)):
                    if getDistSquared([x,y], ndots[m]) + sys.float_info.epsilon < rSquared:
                        flag = False
                        break
                if flag:
                    print('No')
                    return 0

    for i in range(len(importants)):
        for j in range(i+1, len(importants)):
            x,y = getMidPoint(importants[i], importants[j])
            rSquared = getDistSquared([x,y], importants[i])
            flag = True

            for l in range(len(importants)):
                if getDistSquared([x,y], importants[l]) - rSquared > sys.float_info.epsilon:
                    flag = False
                    break
            if not flag:  continue
            for m in range(len(ndots)):
                if getDistSquared([x,y], ndots[m]) + sys.float_info.epsilon < rSquared:
                    flag = False
                    break
            if flag:
                print('No')
                return 0
    print('Yes')

if len(dots) > 1:
    main()
else:
    print('No')