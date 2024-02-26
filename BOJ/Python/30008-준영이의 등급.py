n, k = map(int, input().split())
g = [int(i) for i in input().split()]
a = [4, 11, 23, 40, 60, 77, 89, 96, 100]
for gg in g:
    t = gg*100 // n
    for i in range(len(a)):
        if t <= a[i]:
            print(i + 1, end=' ')
            break

