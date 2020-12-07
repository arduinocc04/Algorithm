import sys, math

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
def getDistSquared(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
def monotoneChain(dots):
    dots.sort()

    lower = []
    for d in dots:
        while len(lower) >= 2 and ccw(lower[-2], lower[-1], d) < 0:
            lower.pop()
        lower.append(d)

    upper = []
    for d in reversed(dots):
        while len(upper) >= 2 and ccw(upper[-2], upper[-1], d) < 0:
            upper.pop()
        upper.append(d)
    return lower[:-1] + upper[:-1]
def isDotInPoly(dots, dot):
    prev = ccw(dot, dots[0], dots[1])
    for i in range(len(dots)-2):
        if prev * ccw(dot, dots[i+1], dots[i+2]) < 0:
            return False
    return True

if len(dots) > 1:
    x = 0
    y = 0
    for i in range(len(dots)):
        x += dots[i][0]
        y += dots[i][1]
    x /= len(dots)
    y /= len(dots)
    ratio = 1
    #nratio = 1
    maxVal = 0
    #flag3 = False
    for _ in range(10000):
        maxVal = 0
        maxIn = 0
        for i in range(len(dots)):
            if (tmp:= getDistSquared([x,y], dots[i])) > maxVal:
                maxVal = tmp
                maxIn = i
        x += (dots[maxIn][0] - x) * ratio
        y += (dots[maxIn][1] - y) * ratio
        ratio *= 0.995
        #nratio *= 0.999
    flag = True
    epsilon = (maxVal*1e-15)
    for i in range(len(ndots)):
        if getDistSquared(ndots[i], [x,y]) - maxVal < epsilon:
            flag = False
            break
    if flag:# and not flag3:
        print('No')
    else:
        x = 0
        y = 0
        ratio = 0.1
        for i in range(len(dots)):
            x += dots[i][0]
            y += dots[i][1]
        x /= len(dots)
        y /= len(dots)
        minVal = 999999999999999999999999999999999999999999999
        for i in ndots:
            minVal = min(minVal,getDistSquared([x,y], i))
        for _ in range(10000):
            r = getDistSquared(dots[0], [x,y])
            for i in range(1, len(dots)):
                r = max(r, getDistSquared(dots[i], [x,y]))
            if minVal - r < 1e-9:
                minVal = 0
                minIn = 0
                for i in range(len(ndots)):
                    if (tmp:= getDistSquared([x,y], ndots[i])) < minVal:
                        minVal = tmp
                        minIn = i
                if minVal - r < 1e-9:
                    tmp = (math.sqrt(maxVal) - math.sqrt(minVal))*ratio/1.414213562
                    if ndots[minIn][0] > x: x -= tmp
                    else: x += tmp
                    if ndots[minIn][1] > y: y -= tmp
                    else: y += tmp
                else: break
                ratio *= 0.999
            else: break
        flag2 = True
        for i in range(len(ndots)):
            if getDistSquared(ndots[i], [x,y]) - r < 1e-9:
                flag2 = False
                break
        if r > 1e11:
            flag2 = False
        if flag2:
            print('No')
        else:
            dots = monotoneChain(dots)
            flag = True
            for i in range(len(ndots)):
                if isDotInPoly(dots, ndots[i]):
                    flag = False
                    break
            if flag: print('No')
            else: print('Yes')
else:
    print('No')