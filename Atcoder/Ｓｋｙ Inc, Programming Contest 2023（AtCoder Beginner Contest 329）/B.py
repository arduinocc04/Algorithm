n = int(input())
a = [int(i) for i in input().split()]
a.sort()
a = a[::-1]
for i in range(n):
    if a[i] != a[0]:
        print(a[i])
        break

