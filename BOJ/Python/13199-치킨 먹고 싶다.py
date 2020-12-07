import sys
for _ in range(int(input())):
    cPrice, money, couponNeed, couponGiven = map(int, sys.stdin.readline().split())
    do, sang = 0, 0
    chickenCnt = money//cPrice
    gotCoupon = chickenCnt*couponGiven
    do = chickenCnt + gotCoupon//couponNeed
    sang = chickenCnt + (gotCoupon + gotCoupon//couponNeed)//couponNeed
    sang = 0
    cpn = 0
    while money >= 0:
        cpn += couponGiven
        if couponNeed <= cpn:
            cpn -= couponNeed
            sang += 1
        else:
            sang += 1
            money -= cPrice
    
    sys.stdout.write(str(sang-1-do) + '\n')