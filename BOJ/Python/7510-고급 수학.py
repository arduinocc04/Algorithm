for i in range(1, int(input()) + 1):
    a = [int(j) for j in input().split()]
    a.sort()
    if a[2]**2 == a[1]**2 + a[0]**2:
        print(f"Scenario #{i}:\nyes\n")
    else: print(f"Scenario #{i}:\nno\n")
