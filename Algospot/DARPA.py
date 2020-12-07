# DARPA
import sys
input = sys.stdin.readline

def isPossible(n, target):
    cnt = 0
    prev = -1312121211212
    for i in range(len(possible)):
        if possible[i] - prev >= n:
            cnt += 1
            prev = possible[i]
    return cnt >= target

def round(n, digit):
    return int((n*(10**digit) + 0.5))/(10**digit)

for _ in range(int(input())):
    n,m = map(int, input().split())
    possible = [float(i) for i in input().split()]
    lo = 0
    hi = 240
    for i in range(100):
        mid = (lo + hi)/2
        if isPossible(mid, n):
            lo = mid
        else:
            hi = mid
    print("%.2f" % (round(lo, 2)))