for _ in range(int(input())):
    n = int(input())
    for i in range(32):
        if n & (1 << i):
            print(i, end=' ')
    print()
