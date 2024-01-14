n = int(input())
for i in range(n - 1, -1, -1):
    print(" "*i + "*"*(2*(n - i) -1) + " "*i)
for i in range(1, n):
    print(" "*i + "*"*(2*(n - i) -1) + " "*i)
