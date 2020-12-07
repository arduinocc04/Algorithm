#================에라토스테네스의 체
nums = []
for i in range(10000):
    nums.append(i+1)
del nums[0]#del 1
decimalList = []
while len(nums) != 0:
    delList = []
    decimalList.append(nums[0])
    for i in range(len(nums)-1):
        if nums[i+1]%nums[0] == 0:
            delList.append(i+1)
            
    for i in range(len(delList)):
        del nums[delList[i]-i]
    del nums[0]
#================================
def findMinDecimalIndex(minimumVal):
    first, last = 0, len(decimalList)-1
    while first <= last:
        mid = (first+last)//2
        if decimalList[mid] == minimumVal:
            break
        if decimalList[mid] > minimumVal:
            last = mid - 1
        else:
            first = mid +1
    if decimalList[mid]>=minimumVal:
        return mid
    else:
        return mid + 1
    
startNum = int(input())
finishNum = int(input())

i = findMinDecimalIndex(startNum)
count = 0
minVal = decimalList[i]
try:
    while decimalList[i] <= finishNum:
        count += decimalList[i]
        i += 1
except:    pass

if not count:
    print(-1)
else:
    print(count)
    print(minVal)
