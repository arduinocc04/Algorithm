for _ in range(int(input())):
    a = int(input())
    i = 1
    for j in range(1, a + 1):
        i *= j
    i = str(i)
    for x in reversed(i):
        if x != '0':
            print(x)
            break

