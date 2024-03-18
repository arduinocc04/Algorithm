n = int(input())
a = [0, 1, 2, 3]
for i in range(n):
    c, d = map(int, input().split())
    j = a.find(c)
    k = a.find(d)
    tmp = a[j]
    a[j] = a[k]
    a[k] = tmp
print(a[1])
