import sys
input = sys.stdin.readline
n = int(input())
a = [int(i) for i in input().split()]
m = int(input())

segTree = [None]*(4*n)
def calc(start:int, finish:int, index:int) -> int:
    global segTree
    if start == finish:
        segTree[index] = a[start]
        return a[start]
    mid = (start + finish)//2
    segTree[index] = min(calc(start, mid, 2*index), calc(mid + 1, finish, 2*index + 1))
    return segTree[index]

def getMin(left:int, right:int, start:int, end:int, index:int) -> int:
    if right < start or end < left:
        return 9999999999
    if start <= left and end >= right:
        return segTree[index]

    mid = (left + right)//2
    return min(getMin(left, mid, start, end, index*2), getMin(mid+1, right, start, end, index*2 + 1))

def update(start:int, end:int, index:int, diff:int, targetNode:int) -> None:
    global segTree
    if start <= targetNode <= end:
        segTree[index] = min(diff, segTree[index])
        if start == end:
            return
        mid = (start + end)//2
        update(start, mid, index*2, diff, targetNode)
        update(mid+1, end, index*2 + 1, diff, targetNode)

calc(0, n-1, 1)

for _ in range(m):
    cmd, i, j = map(int, input().split())
    if cmd == 1:
        update(0, n-1, 1, j, i-1)
        a[i-1] = j
    else:
        print(getMin(0, n-1, i-1, j-1, 1))