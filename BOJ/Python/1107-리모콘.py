channel = int(input())
wrBtnCount = int(input())
wrs = [int(i) for i in input().split()]

def calc(n:int) -> int:
    if n == 0:
        return int(not 0 in wrs)
    cnt = 0
    while n > 0:
        cnt += 1
        a = n%10
        n //= 10
        if a in wrs:
            return 0
    return cnt
    
if wrBtnCount == 10:
    print(abs(channel-100))

elif wrBtnCount == 0:
    print(min(calc(channel), abs(channel-100)))

else:
    min_ = abs(100-channel)
    for i in range(1000000):
        if a:= calc(i):
            if abs(i-channel) + a < min_:
                min_ = abs(i-channel) + a
    print(min_)