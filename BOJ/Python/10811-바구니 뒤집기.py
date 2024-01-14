n, m = map(int, input().split())
bs = [i for i in range(n + 1)]
for _ in range(m):
    i, j = map(int, input().split())
    tmp = []
    for k in range(i, j + 1):
        tmp.append(bs[k])
    for k in range(i, j + 1):
        bs[k] = tmp[-k-1]

print(*bs[1:])
