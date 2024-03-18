n = int(input())
s = [[int(i) for i in input().split()] for _ in range(n)]

c = [0]*n
for g in range(3):
    for i in range(n):
        flag = True
        for j in range(n):
            if j == i: continue
            if s[i][g] == s[j][g]:
                flag = False
                break
        if flag:
            c[i] += s[i][g]
print(*c, sep ='\n')
