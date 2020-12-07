import sys
input = sys.stdin.readline

n, m = map(int, input().split())

nums = [int(input()) for _ in range(n)]

segTree = [None]*(4*n)

def init(start, end, index):
    global segTree
    if start == end: 
        segTree[index] = [nums[start], nums[start]]
        return segTree[index]
    else:
        mid = (start+end)//2
        minA, maxA = init(start, mid, index*2)
        minB, maxB = init(mid+1, end, index*2+1)
        segTree[index] = [min(minA,minB), max(maxA,maxB)]
        return segTree[index]

init(0, n-1, 1)

def getMinMax(left, right, start, end, index):
    if end < left or start > right:  return [100000000000, -10000000000]
    if start <= left and right <= end:
        return segTree[index]
    mid = (left + right)//2
    aMin, aMax = getMinMax(left, mid, start, end, index*2)
    bMin, bMax = getMinMax(mid+1, right, start, end, index*2+1)
    return min(aMin, bMin), max(aMax, bMax)

for _ in range(m):
    a,b = map(int, input().split())
    print(*getMinMax(0, n-1, a-1, b-1, 1))