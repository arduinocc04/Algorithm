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

if len(dots) > 2:
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
        """
        minVal = float('inf')
        minIn = 0
        for i in range(len(ndots)):
            if (tmp:= getDistSquared([x,y], ndots[i])) < minVal:
                minVal = tmp
                minIn = i
        if minVal < maxVal:
            tmp = (math.sqrt(maxVal) - math.sqrt(minVal))/1.414213562
            if ndots[minIn][0] > x:
                x -= tmp
            else:
                x += tmp
            if ndots[minIn][1] > y:
                y -= tmp
            else:
                x += tmp
        """
        x += (dots[maxIn][0] - x) * ratio
        y += (dots[maxIn][1] - y) * ratio
        """
        if abs(x) > 1e70 or abs(y) > 1e70:
            flag3 = True
            break
        """
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
        """
        print('Yes')
elif len(dots) == 2:
    if len(ndots) < 2: 
        print('No')
    else:
        """
        x = 0
        y = 0
        ratio = 1
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
                    tmp = (math.sqrt(maxVal) - math.sqrt(minVal))/1.414213562
                    if ndots[minIn][0] > x: x -= tmp
                    else: x += tmp
                    if ndots[minIn][1] > y: y -= tmp
                    else: y += tmp
                else: break
            else: break
        flag2 = True
        for i in range(len(ndots)):
            if getDistSquared(ndots[i], [x,y]) - r < 1e-9:
                flag2 = False
                break
        if r > 1e9:
            flag2 = False
        if flag2:
            print('No')
        else:
            flag = True
            for i in range(len(dots)):
                for j in range(len(ndots)):
                    if ccw(dots[i-1], dots[i], ndots[j]) != 0:
                        flag = False
                        break
            flag = False
            if flag: print('No')
            else: print('Yes')

else:
    print('No')