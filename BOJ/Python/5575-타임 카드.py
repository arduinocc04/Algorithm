for i in range(3):
    a = [int(i) for i in input().split()]
    startTime = a[:3]
    finishTime = a[3:]
    sec = finishTime[2]-startTime[2]
    minute = 0
    hour = 0
    if sec<0:
        minute = -1
        sec += 60
    minute += finishTime[1]-startTime[1]
    if minute<0:
        hour = -1
        minute += 60
    hour += finishTime[0]-startTime[0]
    print(f'{hour} {minute} {sec}')