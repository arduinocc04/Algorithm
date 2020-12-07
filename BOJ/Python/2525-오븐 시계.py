nowHour, nowMinute = [int(i) for i in input().split()]
plusMinute = int(input())
nowMinute += plusMinute
if nowMinute>=60:
    nowHour += nowMinute//60
    nowMinute %= 60
if nowHour>23:
    nowHour %= 24
print(f'{nowHour} {nowMinute}')