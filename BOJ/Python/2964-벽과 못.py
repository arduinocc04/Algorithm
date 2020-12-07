import sys
input = sys.stdin.readline

n = int(input())
dots = [[int(i) for i in input().split()] + [j] for j in range(n)]
dots.sort(key=lambda x:(x[0], x[1]))
a = sorted(dots, key=lambda x:(x[1], x[0]))
used = [False]*n

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    lower = []
    for i in range(n):
        if used[i]: continue
        while len(lower) >= 2 and ccw(dots[lower[-2]][:2], dots[lower[-1]][:2], dots[i][:2]) <= 0:
            lower.pop()
        lower.append(i)

    upper = []
    for i in range(n):
        if used[n-1-i]: continue
        while len(upper) >= 2 and ccw(dots[upper[-2]][:2], dots[upper[-1]][:2], dots[n-1-i][:2]) <= 0:
            upper.pop()
        upper.append(n-1-i)
    return lower[:-1] + upper[:-1]

def getArea(convexHull):
    s = 0
    for i in range(len(convexHull)-1):
        s += ccw(dots[convexHull[0]], dots[convexHull[i]], dots[convexHull[i+1]])
    return int(abs(s)*5)/10

cmd = input()
for i in range(len(cmd)):
    if i != len(cmd)-1:
        print(getArea(monotonechain(dots)))
    if cmd[i] == 'L':
        for j in range(n):
            if not used[dots[j][-1]]:
                used[dots[j][-1]] = True
                break
    elif cmd[i] == 'R':
        for j in range(n):
            if not used[dots[n-1-j][-1]]:
                used[dots[n-1-j][-1]] = True
                break
    elif cmd[i] == 'D':
        for j in range(n):
            if not used[a[j][-1]]:
                used[a[j][-1]] = True
                break
    else:
        for j in range(n):
            if not used[a[n-1-j][-1]]:
                used[a[n-1-j][-1]] = True
                break