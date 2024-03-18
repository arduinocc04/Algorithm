a = ["black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"]
s = ''
for i in range(2):
    t = input()
    for j in range(len(a)):
        if a[j] == t:
            s += str(j)
s = int(s)
t = input()
for i in range(len(a)):
    if a[i] == t:
        s *= 10**i
print(s)
