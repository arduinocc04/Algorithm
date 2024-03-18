a = input()
b = input()
c = ""
d = 'abcdefghijklmnopqrstuvwxyz'
for i in range(len(a)):
    if a[i] == ' ':
        c += ' '
        continue
    c += d[(ord(a[i]) - ord('a') - ord(b[i % len(b)]) - 1 + ord('a')) % len(d)]
print(c)


