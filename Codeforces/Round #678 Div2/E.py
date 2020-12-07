n = int(input())
nums = [int(i) for i in input().split()]
flags = [False] + [True]*(n+3)
segTree = [-1]*4*n
def init(start, end, index):
    global segTree, flags
    if start == end: 
        flags[1 if nums[start] != 1 else 2] = False
        segTree[index] = [1 if nums[start] != 1 else 2]
        return segTree[index]
    else:
        mid = (start+end)//2
        a = init(start, mid, index*2)
        b = init(mid+1, end, index*2+1)
        segTree[index] = a+b
        for i in segTree[index]:
            flags[i] = False
        return segTree[index]

init(0, n-1, 1)
for i in range(len(flags)):
    if flags[i]:
        print(i)
        break