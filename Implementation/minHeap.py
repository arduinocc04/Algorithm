class Heap:
    def __init__(self, val:list=[]) -> None:
        self.list = val

    def swap(self, index1:int, index2:int) -> None:
        tmp = self.list[index1]
        self.list[index1] = self.list[index2]
        self.list[index2] = tmp

    def getLChild(self, index:int) -> int:
        return 2*(index+1) - 1
    
    def getRChild(self, index:int) -> int:
        return 2*(index+1)

    def getParent(self, index:int) -> int:
        return (index+1)//2
    
    def add(self, val:int) -> None:
        self.list.append(val)
    
    def pop(self) -> int:
        res = self.list[0]
        self.swap(0, len(self.list) - 1)