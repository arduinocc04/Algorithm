a = input()
tmp = ['']*len(a)
tmp[0] = a
for i in range(1, len(a)):
    for j in range(1, i+1):
        tmp[j] += a[i]
tmp.sort()
for i in tmp: print(i)
