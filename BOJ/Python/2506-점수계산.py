n = int(input())
ss = [int(i) for i in input().split()]
ans = 0
s = 1
for i in ss:
    if i == 1:
        ans += s
        s += 1
    else:
        s = 1
print(ans)
