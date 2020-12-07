class Node:
    def __init__(self, val):
        self.val = val 
        self.next = None #연결을 위해
        self.prev = None

class LinkedList:
    def __init__(self): #초기화
        self.head = None
        self.tail = None
    
    def appendRight(self, val):
        tmp = Node(val)
        if self.head == None: #이 원소가 처음이라면
            self.head = tmp #헤드를 이 원소로.
            self.tail = tmp #꼬리도 이 원소로.
        else:
            prevTmp = self.tail
            self.tail.next = tmp
            self.tail = tmp
            self.tail.prev = prevTmp

    def appendLeft(self, val):
        tmp = Node(val)
        if self.head == None:
            self.head = tmp
            self.tail = tmp
        else:
            prevHead = self.head
            self.head.prev = tmp
            self.head = tmp
            self.head.next = prevHead
    
    def popLeft(self):
        if self.head == None:
            return None
        else:
            tmp = self.head.val
            self.head = self.head.next
            self.head.prev = None
            return tmp
    
    def popRight(self): #맨 오른쪽에 있는 값 뽑아내기
        if self.tail == None:
            return None
        else:
            tmp = self.tail.val
            self.tail = self.tail.prev#꼬리를 오른쪽에서 두번째로 바꿈.
            self.tail.next = None
            return tmp

    def travleToRight(self): #왼쪽에서 오른쪽으로 순회
        node = self.head
        while node.next != None:
            print(node.val)
            node = node.next
        print(node.val)
    
    def travleToLeft(self): #오른쪽에서 왼쪽으로 순회
        node = self.tail
        while node.prev != None:
            print(node.val)
            node = node.prev
        print(node.val)

if __name__ == '__main__':
    a = LinkedList()
    for i in range(10):
        a.appendLeft(i)
    a.travleToRight()
    a.travleToLeft()