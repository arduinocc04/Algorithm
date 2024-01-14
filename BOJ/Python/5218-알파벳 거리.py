for _ in range(int(input())):
    a, b = input().split()
    d = []
    for i in range(len(a)):
        t = ord(a[i]) - ord(b[i])
        if t >= 0: d.append(t)
        else: d.append(26  + t)
    print("Distances: ", end='')
    print(*d)
