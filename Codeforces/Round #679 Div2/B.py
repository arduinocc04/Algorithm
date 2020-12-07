import sys
input = sys.stdin.readline

a = []
b = []
aA = a.append
bA = b.append
for _ in range(int(input())):
    n,m = map(int, input().split())
    a.clear()
    b.clear()
    for i in range(n):
        aA([int(j) for j in input().split()])
    for i in range(m):
        bA([int(j) for j in input().split()])
    ans = []
    std = False

    for i in range(n):
        for j in range(m):
            if b[0][0] == a[i][j]:
                std = j
                break
        if std: break
    for i in range(n):
        for j in range(n):
            if b[0][i] == a[j][std]:
                ans.append(j)
                break
    for i in ans:
        print(*a[i]) 