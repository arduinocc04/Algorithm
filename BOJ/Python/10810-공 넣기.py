n, m = map(int, input().split())
basket = [0]*110
qs = []
for i in range(m):
    i, j, k = map(int, input().split())
    qs.append((i, j, k))

for i, j, k in reversed(qs):
    for l in range(i, j + 1):
        if basket[l] == 0:
            basket[l] = k

print(*basket[1:n + 1])
