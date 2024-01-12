n, m = map(int, input().split())
s = input()
t = input()

i = 0
j = 0
flag = True
if s[-1] != t[-1]:
    flag = False
    j = n + 1
while j < n:
    print(i, j, s[j], t[i])
    if s[j] != t[i]:
        if i == 0:
            flag = False
            break
        else:
            i = 0
    else:
        i += 1
        i %= m
        j += 1
if flag:
    print("Yes")
else:
    print("No")
