n, m = map(int, input().split())
bs = [i for i in range(n + 1)]

for _ in range(m):
    i, j, k = map(int, input().split())
    t = []
    for l in range(k, j + 1):
        t.append(bs[l])
    for l in range(i, k): t.append(bs[l])
    for l in range(len(t)):
        bs[i + l] = t[l]
print(*bs[1:])
