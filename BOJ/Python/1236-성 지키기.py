n, m = map(int, input().split())
a = [input() for _ in range(n)]
usedx = [False]*n
usedy = [False]*m
for i in range(n):
    for j in range(m):
        if a[i][j] == 'X':
            usedx[i] = True
            usedy[j] = True
print(max(usedx.count(False), usedy.count(False)))
