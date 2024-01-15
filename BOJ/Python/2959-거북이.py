a = [int(i) for i in input().split()]
m = -1
for i in range(len(a)):
    for j in range(i + 1, len(a)):
        t = []
        for k in range(len(a)):
            if k == i: continue
            if k == j: continue
            t.append(a[k])
        m = max(m, min(a[i], a[j])*min(t[0], t[1]))

print(m)
