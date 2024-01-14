n = int(input())
s = -1
for _ in range(n):
    a = [int(i) for i in input().split()]
    a.sort()
    if a[0] == a[2]:
        s = max(10_000 + a[0]*1_000, s)
    elif a[0] == a[1] or a[1] == a[2]:
        s = max(1_000 + a[1]*100, s)
    else:
        s = max(max(a)*100, s)
print(s)
