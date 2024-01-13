import sys
input = sys.stdin.readline

def calc(i, j, k):
    return abs(a[i] - a[j])*b[k]

def ca(w, k):
    return w*b[k]

def upper_bound(width, x):
    lo = 0
    hi = m
    while lo < hi:
        mid = (lo + hi)//2
        if ca(width, mid) <= x:
            lo = mid + 1
        else:
            hi = mid
    return lo

n, m, r = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

b.sort()

maxVal = -1
for i in range(n):
    for j in range(i + 1, n):
        jjjj = upper_bound(abs(a[i] - a[j]), 2*r)
        if jjjj == 0: continue
        jjjj -= 1
        t = calc(i, j, jjjj)
        maxVal = max(t, maxVal)

c = maxVal//2
if maxVal >= 0: print(f"{c}.0" if maxVal % 2 == 0 else f"{c}.5")
else: print(-1)
