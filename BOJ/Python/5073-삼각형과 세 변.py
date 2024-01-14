while True:
    a = [int(i) for i in input().split()]
    if sum(a) == 0:
        break
    a.sort()
    if a[2] >= a[0] + a[1]:
        print("Invalid")
    elif a[0] == a[1] and a[1] == a[2]:
        print("Equilateral")
    elif a[0] == a[1] or a[1] == a[2]:
        print("Isosceles")
    else:
        print("Scalene")
