a = [int(input()) for _ in range(9)]
s = sum(a)
for i in range(9):
    for j in range(i + 1, 9):
        if s - a[i] - a[j] == 100:
            for k in range(9):
                if k == i: continue
                if k == j: continue
                print(a[k])
