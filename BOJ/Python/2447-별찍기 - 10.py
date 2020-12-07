def do(n, size, x, y):
    global value
    if size == 1:
        if not n:
            value[x-1][y-1] = ' '
    else:
        a = n and False
        s = size//3
        b = x//3
        c = y//3
        do(a, s, b, c)
        do(a, s, 2*b, c)
        do(a, s, x, c)

        do(a, s, b, 2*c)
        do(False, s, 2*b, 2*c)
        do(a, s, x, 2*c)

        do(a, s, b, y)
        do(a, s, 2*b, y)
        do(a, s, x, y)
        


value = []
a = int(input())
for i in range(a):
    value.append(['*']*a)
do(True, a, a, a)
for i in value:
    for a in i:
        print(a, end='')
    print()