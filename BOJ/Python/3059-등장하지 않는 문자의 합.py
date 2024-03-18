A="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for _ in range(int(input())):
    a = input()
    s = 0
    for i in A:
        if i not in a:
            s += ord(i)
    print(s)
