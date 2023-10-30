a = [input().split() for _ in range(8)]
a.sort(key = lambda x: x[0])
s1, s2 = 0, 0
s = [10, 8, 6, 5, 4, 3, 2, 1]
for i in range(8):
    if a[i][-1] == 'R': s1 += s[i]
    else: s2 += s[i]
if s1 > s2: print("Red")
else: print("Blue")