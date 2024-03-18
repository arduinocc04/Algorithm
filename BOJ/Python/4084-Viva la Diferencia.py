while True:
    a = [int(i) for i in input().split()]
    if sum(a) == 0: break
    j = 0
    while True:
        if a[0] == a[1] == a[2] == a[3]: break
        b = [0]*4
        for i in range(3):
            b[i] = abs(a[i] - a[i + 1])
        b[3] = abs(a[3] - a[0])
        a = b[:]
        j += 1
    print(j)
