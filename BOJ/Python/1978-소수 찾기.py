_ = input()
numList = [int(i) for i in input().split()]
numList.sort()
nums = []
for i in range(1000):
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

decimalCount = 0
for num in numList:
    if num in decimalList:
        decimalCount += 1
print(decimalCount)