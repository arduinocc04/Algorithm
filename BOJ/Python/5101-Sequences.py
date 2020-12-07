while True:
    a = [int(i) for i in input().split()]
    if not(a[0] or a[1] or a[2]):
        break
    startNum = a[0]
    difference = a[1]
    if difference>0:
        flag = a[2]>startNum
    else:
        flag = a[2]<startNum
    if (a[2]-startNum)%difference == 0 and flag:
        b = startNum-difference
        print((a[2]-b)//difference)
    else:
        print('X')