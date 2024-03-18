n = int(input())
m = [[int(i) for i in input().split()] for _ in range(n)]

mm = 0
mc = -1
for i in range(n):
    cnt = 0
    for j in range(n):
        for k in range(5):
            if m[i][k] == m[j][k]:
                cnt += 1
                break
    if cnt > mc:
        mc = cnt
        mm = i
print(mm + 1)
