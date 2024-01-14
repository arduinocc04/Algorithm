a = [input() for _ in range(4)]
ans = 0
b = ["ABCD", "EFGH", "IJKL", "MNO."]
for i in range(4):
    for j in range(4):
        if a[i][j] == '.': continue
        flag = False
        for k in range(4):
            for l in range(4):
                if a[i][j] == b[k][l]:
                    ans += abs(i - k) + abs(j - l)
                    flag = True
                    break
            if flag: break
print(ans)
