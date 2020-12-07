import sys
input = sys.stdin.readline

def calc(start:int, finish:int, index:int) -> int:
    global segTree
    if start == finish:
        segTree[index] = x[start]
        return x[start]
    mid = (start + finish)//2
    segTree[index] = calc(start, mid, 2*index) * calc(mid + 1, finish, 2*index + 1)
    return segTree[index]

def getTimes(left:int, right:int, start:int, end:int, index:int) -> int:
    if right < start or end < left:
        return 1
    if start <= left and end >= right:
        return segTree[index]

    mid = (left + right)//2
    return getTimes(left, mid, start, end, index*2) * getTimes(mid+1, right, start, end, index*2 + 1)

def update(start:int, end:int, index:int, diff:int, targetNode:int) -> None:
    global segTree
    if start <= targetNode <= end:
        segTree[index] *=  diff
        if start == end:
            return
        mid = (start + end)//2
        update(start, mid, index*2, diff, targetNode)
        update(mid+1, end, index*2 + 1, diff, targetNode)

while True:
    try:
        n,k = map(int, input().split())
    except EOFError:
        break
    x = [int(i) for i in input().split()]
    segTree = [None]*(4*n)
    calc(0, n-1, 1)
    for i in range(k):
        cmd, a,b = input().split()
        a = int(a)-1
        b = int(b)
        if cmd == 'C':
            if x[a] == 0:
                x[a] = 1
            update(0, n-1, 1, b/x[a], a)
            x[a] = b
        elif cmd == 'P':
            tmp = getTimes(a, b-1, 0, n-1, 1)
            if tmp > 0:
                print('+', end='')
            elif tmp < 0:
                print('-', end='')
            elif tmp == 0:
                print('0', end='')
