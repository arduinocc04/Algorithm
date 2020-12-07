a = [int(i) for i in input().split()]
day = a[0]
hour = a[1]
minute = a[2]
totalMinute = 0
if minute<11:
    hour -= 1
    minute += 60
totalMinute += minute-11
if hour<11:
    day -= 1
    hour += 24
totalMinute += (hour-11)*60
totalMinute += (day-11)*24*60
if totalMinute>=0:
    print(totalMinute)
else:
    print(-1)