n, m = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
for x in b:
    for i in range(len(a)):
        if a[i] >= x:
            a[i] -= x
            break
print(sum(a))
