import sys
input = sys.stdin.readline

def ccw(p1, p2, p3):
    return p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1])

def monotonechain(dots):
    lower = []
    for i in range(len(dots)):
        if used[dots[i][-1]] == 0:
            while (len(lower) >= 2 and ccw(dots[lower[-2]], dots[lower[-1]], dots[i][:2]) <= 0):
                if len(lower) == 0:  return None
                lower.pop()
            lower.append(i)

    upper = []
    for i in range(len(dots)):
        if used[dots[n-1-i][-1]] == 0:
            while (len(upper) >= 2 and ccw(dots[upper[-2]], dots[upper[-1]], dots[n-1-i][:2]) <= 0):
                upper.pop()
            upper.append(n-1-i)
    return lower[:-1] + upper[:-1]

n = int(input())
dots = [[int(i) for i in input().split()]+[j] for j in range(n)]
used = [0]*n
dots.sort(key=lambda x:(x[0],x[1]))
cnt = 1
while True:
    a = monotonechain(dots)
    if len(a) <= 2:
        break
    for i in a:
        used[dots[i][-1]] = cnt
    cnt += 1
print(*used)