import sys
input = sys.stdin.readline
n,m,k = map(int, input().split())
a = [int(input()) for _ in range(n)]
segTree = [None]*(4*n)
def calc(start:int, finish:int, index:int) -> int:
    global segTree
    if start == finish:
        segTree[index] = a[start]
        return a[start]
    mid = (start + finish)//2
    segTree[index] = calc(start, mid, 2*index) + calc(mid + 1, finish, 2*index + 1)
    return segTree[index]

def getSum(left:int, right:int, start:int, end:int, index:int) -> int:
    if right < start or end < left:
        return 0
    if start <= left and end >= right:
        return segTree[index]

    mid = (left + right)//2
    return getSum(left, mid, start, end, index*2) + getSum(mid+1, right, start, end, index*2 + 1)

def update(start:int, end:int, index:int, diff:int, targetNode:int) -> None:
    global segTree
    if start <= targetNode <= end:
        segTree[index] +=  diff
        if start == end:
            return
        mid = (start + end)//2
        update(start, mid, index*2, diff, targetNode)
        update(mid+1, end, index*2 + 1, diff, targetNode)

calc(0, n-1, 1)

for _ in range(m+k):
    cmd, b, c = map(int, input().split())
    if cmd == 1:
        update(0,n-1, 1, c-a[b-1], b-1)
        a[b-1] = c
    else:
        print(getSum(0, n-1, b-1, c-1, 1))