import typing
class SegmentTree:
    def __init__(self, val:typing.List):
        self.items = val
        self.segTree = [None]*(len(val)*4)
        self.init(0, len(val)-1, 1)

    def init(self, start:int, finish:int, index:int) -> int:
        if start == finish:
            self.segTree[index] = self.items[start]
            return self.items[start]
        mid = (start + finish)//2
        self.segTree[index] = self.init(start, mid, 2*index) + self.init(mid + 1, finish, 2*index + 1)
        return self.segTree[index]

    def getSum(self, left:int, right:int, start:int, end:int, index:int) -> int:
        if right < start or end < left:
            return 0
        if start <= left and end >= right:
            return self.segTree[index]

        mid = (left + right)//2
        return self.getSum(left, mid, start, end, index*2) + self.getSum(mid+1, right, start, end, index*2 + 1)

    def update(self, start:int, end:int, index:int, diff:int, targetNode:int) -> None:
        if start <= targetNode <= end:
            self.segTree[index] +=  diff
            if start == end:
                return
            mid = (start + end)//2
            self.update(start, mid, index*2, diff, targetNode)
            self.update(mid+1, end, index*2 + 1, diff, targetNode)

    def change(self, itemIndex:int, val:int) -> None:
        self.update(0, len(self.items)-1, 1, val-self.items[itemIndex], itemIndex)
        self.items[itemIndex] = val

if __name__ == '__main__':
    seg = SegmentTree([1, 2, 3, 4, 5])
    seg.change(2, 6)
    print(seg.getSum(0, len(seg.items)-1, 1, 4, 1))
    seg.change(4, 2)
    print(seg.getSum(0, len(seg.items)-1, 2, 4, 1))