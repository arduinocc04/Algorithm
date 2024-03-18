n = int(input())
m = -1
for _ in range(n):
    a = [int(i) for i in input().split()]
    a.sort()
    if a[0] == a[-1]:
        ans = 50_000 + a[0]*5_000
    elif a[0] == a[1] == a[2] or a[1] == a[2] == a[3]:
        ans = 10_000 + a[1]*1_000
    elif a[0] == a[1] and a[2] == a[3]:
        ans = 2_000 + a[0]*500 + a[2]*500
    elif a[0] == a[1] or a[1] == a[2] or a[2] == a[3]:
        if a[2] == a[3]:
            ans = 1_000 + a[2]*100
        else:
            ans = 1_000 + a[1]*100
    else: ans = max(a)*100
    m = max(ans, m)
print(m)
