for _ in range(int(input())):
    a = [int(i) for i in input().split()]
    hp = a[0] + a[4]
    mp = a[1] + a[5]
    at = a[2] + a[6]
    de = a[3] + a[7]
    print(max(hp, 1) + 5*max(mp,1) + 2*max(0, at)  + 2*de)
