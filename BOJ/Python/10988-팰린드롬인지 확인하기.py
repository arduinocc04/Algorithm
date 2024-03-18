a = input()
f = 1
for i in range(len(a)):
    if a[i] != a[-i - 1]:
        f = 0
        break
print(f)
