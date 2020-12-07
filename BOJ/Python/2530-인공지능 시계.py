nowHour, nowMinute, nowSecond = [int(i) for i in input().split()]
plusSecond = int(input())
nowSecond += plusSecond
if nowSecond>= 60:
    nowMinute += nowSecond//60
    nowSecond %= 60
if nowMinute>=60:
    nowHour += nowMinute//60
    nowMinute %= 60
if nowHour>23:
    nowHour %= 24
print(f'{nowHour} {nowMinute} {nowSecond}')