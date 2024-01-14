n = int(input())
a = [1, 1]
if n == 1 or n == 2: print(1)
else:
    for i in range(n - 2):
        t = a[0] + a[1]
        a[0] = a[1]
        a[1] = t
    print(t)
