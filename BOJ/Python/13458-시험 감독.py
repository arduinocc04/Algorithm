classCount = int(input())
studentPerClassList = [int(i) for i in input().split()]
maxPrimaryWatch, maxSecondaryWatch = input().split()
maxPrimaryWatch, maxSecondaryWatch = int(maxPrimaryWatch), int(maxSecondaryWatch)

watcherCount = classCount
for studentPerClass in studentPerClassList:
    if studentPerClass-maxPrimaryWatch > 0:
        watcherCount += (studentPerClass-maxPrimaryWatch)//maxSecondaryWatch
        if (studentPerClass-maxPrimaryWatch)%maxSecondaryWatch != 0:
            watcherCount += 1
print(watcherCount)
