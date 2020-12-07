import sys
class MaxHeap:
    def __init__(self):
        self.arr = []
        
    def __len__(self):
        return len(self.arr)
    
    def getParent(self, index:int) ->int:
        return abs(index-1)//2
    
    def getRChild(self, index:int) ->int:
        if 2*(index+1) < len(self.arr):
            return 2*(index+1)
        else:
            return None
        
    def getLChild(self, index:int) -> int:
        if 2*index+1 < len(self.arr):
            return 2*index + 1
        else:
            return None
        
    def swap(self, index1:int, index2:int) -> None:
        tmp = self.arr[index1]
        self.arr[index1] = self.arr[index2]
        self.arr[index2] = tmp
        
    def max3(self, in1:int, in2:int, in3:int) -> None:
        max_ = in1
        if self.arr[in1] < self.arr[in2]:
            max_ = in2
        if self.arr[max_] < self.arr[in3]:
            max_ = in3
        return max_
    
    def max2(self, in1:int, in2:int) -> None:
        max_ = in1
        if self.arr[in1] < self.arr[in2]:
            max_ = in2
        return max_
    
    def push(self, val:int) -> None:
        self.arr.append(val)
        mine = len(self.arr)-1
        parent = self.getParent(mine)
        while self.max2(mine, parent) != parent:
            self.swap(mine, parent)
            mine = parent
            parent = self.getParent(mine)
            
    def pop(self) -> int:
        if len(self.arr) > 3:
            self.swap(0, -1)
            res = self.arr.pop(-1)
            mine = 0
            lChild = 1
            rChild = 2
            while (max_:=self.max3(mine, lChild, rChild)) != mine:
                self.swap(max_, mine)
                mine = max_
                lChild = self.getLChild(mine)
                rChild = self.getRChild(mine)
                if lChild == None:
                    break
                if rChild == None:
                    self.swap(mine, -1)
                    break
            return res
        elif len(self.arr) != 0:
        	self.arr.sort()
        	return self.arr.pop(-1)
        else:
        	return 0
if __name__ == '__main__':
    heap = MaxHeap()
    b = int(input())
    for i in range(b):
        a = int(sys.stdin.readline())
        if a>0:
            heap.push(a)
        else:
            if i != b-1:
                sys.stdout.write(str(heap.pop()) + '\n')
            else:
                sys.stdout.write(str(heap.pop()))