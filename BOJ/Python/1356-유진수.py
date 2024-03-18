n = input()
a = int(n[0])
b = 1
for i in n[1:]:
    b *= int(i)
f = False
if a == b: f = True
for i in range(len(n)):
    a = 1
    b = 1
    for j in n[:i]:
        a *= int(j)
    for j in n[i:]:
        b *= int(j)
    if a == b:
        f = True
        break
if len(n) == 1: f = False
if f: print("YES")
else: print("NO")
