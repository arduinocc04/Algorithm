for _ in range(int(input())):
    a,b = [int(i) for i in input().split()]
    a %= 10
    b = b%4 + 4
    c = a**b%10
    if c:
        print(c)
    else:
        print(10)