import sys
input = sys.stdin.readline
def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])
def monotonechain(dots):
    dots.sort(key=lambda x:(-x[1],x[0]))
    if len(dots) <=1:
        return dots

    left = []
    for d in dots:
        while len(left) >= 2 and ccw(left[-2], left[-1], d) >= 0:
            left.pop()
        left.append(d)

    right = []
    for d in reversed(dots):
        while len(right) >= 2 and ccw(right[-2], right[-1], d) >= 0:
            right.pop()
        right.append(d)
    return left[:-1] + right[:-1]
for _ in range(int(input())):
    n = int(input())
    dots = []
    dA = dots.append
    for i in range((n-1)//5 + 1):
        tmp = [int(k) for k in input().split()]
        for k in range(len(tmp)//2):
            dA([tmp[2*k], tmp[2*k+1]])
    res = monotonechain(dots)
    sys.stdout.write(f'{len(res)}\n')
    for d in res:
        sys.stdout.write(f'{d[0]} {d[1]}\n')