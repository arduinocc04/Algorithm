import sys
sys.setrecursionlimit(1_000_000)
m, n = map(int, input().split())
a = [[0]*n for _ in range(m)]

def mark(i, j, d):
    global a
    a[i][j] = 1
    if d == 3:
        if j < n - 1 and a[i][j+1] == 0:
            mark(i, j + 1, 3)
        else:
            if i < m - 1 and a[i+1][j] == 0:
                a[i][j] = 2
                mark(i + 1, j, 1)
    elif d == 2:
        if i > 0 and a[i - 1][j] == 0:
            mark(i - 1, j, 2)
        else:
            if j < n - 1 and a[i][j + 1] == 0:
                a[i][j] = 2
                mark(i, j + 1, 3)
    elif d == 1:
        if i < m - 1 and a[i + 1][j] == 0:
            mark(i + 1, j, 1)
        else:
            if j > 0 and a[i][j - 1] == 0:
                a[i][j] = 2
                mark(i, j - 1, 0)
    else:
        if j > 0 and a[i][j - 1] == 0:
            mark(i, j - 1, 0)
        else:
            if i > 0 and a[i - 1][j] == 0:
                a[i][j] = 2
                mark(i - 1, j, 2)
mark(0, 0, 3)
cnt = 0
for i in range(m):
    for j in range(n):
        if a[i][j] == 2: cnt += 1
print(cnt)
