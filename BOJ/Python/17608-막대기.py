import sys
stickList = []
a = int(input())
for _ in range(a):
    stickList.append(int(sys.stdin.readline()))
stickCount = 1
pivot = stickList[-1]
for i in range(len(stickList)):
    if stickList[-i-1]>pivot:
        pivot = stickList[-i-1]
        stickCount += 1
print(stickCount)
