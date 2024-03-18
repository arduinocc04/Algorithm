n = int(input())
b = [int(i) for i in input().split()]
a = []
a.append(b[0])
s = a[0]
for i in range(1, n):
    a.append(b[i]*(i + 1) - s)
    s += a[-1]
print(*a)
