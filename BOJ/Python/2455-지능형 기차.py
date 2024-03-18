a = [[int(i) for i in input().split()] for _ in range(4)]
t = a[0][1]
m = a[0][1]
for i in range(1, 4):
    t += -a[i][0] + a[i][1]
    m = max(m, t)
print(m)
