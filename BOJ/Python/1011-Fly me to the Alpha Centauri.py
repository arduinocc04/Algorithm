for _ in range(int(input())):
    x,y = map(int, input().split())
    dist = y-x
    a = 1
    b = 1
    while dist > 0:
        dist -= a
        a += 1
        if dist >= b:
            dist -= b
            b += 1
    print(a + b - 2)