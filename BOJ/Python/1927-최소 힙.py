class Heap:
    def __init__(self):
        self.list = []

    def swap(self, indexA, indexB):
        if self.list[indexA] > self.list[indexB]:
            temp = self.list[indexA]
            self.list[indexA] = self.list[indexB]
            self.list[indexB] = temp

    def add(self, num):
        if len(self.list) > 1:
            nowIndex = 0
        else:
            self.list.append(num)
            
    def pop(self):
        if len(self.list) > 0:
            a = self.list[0]
            del self.list[0]
            return a
        else:
            return 0
    