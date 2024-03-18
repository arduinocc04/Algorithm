for _ in range(int(input())):
    n = int(input())
    a = [['J']*n for _ in range(n)]
    for i in range(n):
        a[0][i] = '#'
        a[i][0] = '#'
        a[-1][i] = '#'
        a[i][-1] = '#'
    for i in range(n):
        for j in range(n):
            print(a[i][j], end='')
        print()
    print()
