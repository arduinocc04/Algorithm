from decimal import *
import sys
input = sys.stdin.readline
getcontext().prec = 300

def calc(l, r):
    if f(l) <= f(r):
        lo = l
        hi = r
        for _ in range(1000):
            mid = Decimal(lo + hi)/Decimal('2')
            if f(mid) > 0:
                hi = mid
            else:
                lo = mid
        return lo
    else:
        lo = l
        hi = r
        for _ in range(1000):
            mid = Decimal(lo + hi)/Decimal('2')
            if f(mid) > 0:
                lo = mid
            else:
                hi = mid
        return lo


def f(x):
    return  a*(Decimal(x)**Decimal('3')) + b*(Decimal(x)**Decimal('2')) + c*Decimal(x) + d

for _ in range(int(input())):
    a, b, c, d = map(Decimal, input().split())
    D = b*b - 3 * a * c
    if D < 0:
        print(calc(-1000100, 1000100))
    else:
        dx1, dx2 = (-b + D**Decimal('0.5'))/(3*a), (-b - D**Decimal('0.5'))/(3*a)
        if(dx1 < dx2):
            tmp = dx2
            dx2 = dx1
            dx1 = tmp
        res  = []
        tmp1, tmp2, tmp3, tmp4 = f(-1000100), f(dx2), f(dx1), f(1000100)
        #print(f'{dx1=} {dx2=}')
       # print(f'{tmp1=} {tmp2=} {tmp3=} {tmp4=}')
        if(tmp1 <= 0 and tmp2 >= 0) or (tmp1 >= 0 and tmp2 <= 0): res.append(calc(-1000100, dx2))
        if(tmp2 <= 0 and tmp3 >= 0) or (tmp2 >= 0 and tmp3 <= 0): res.append(calc(dx2, dx1))
        if(tmp3 <= 0 and tmp4 >= 0) or (tmp3 >= 0 and tmp4 <= 0): res.append(calc(dx1, 1000100))
        res.sort()
        for i in range(len(res)):
            if(abs(int(res[i]) - res[i]) < 1e-15):
                res[i] = int(res[i])
            elif(abs(int(res[i]) + 1 - res[i]) < 1e-15):
                res[i] = int(res[i]) + 1
        toDel = [False, False, False]
        for i in range(len(res)-1):
            if(res[i+1] - res[i]) <= 1e-9:
                toDel[i] = True
        for i in range(len(res)):
            if not toDel[i]: print("%.15f" %res[i], end = ' ')
        print()