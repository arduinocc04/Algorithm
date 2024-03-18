n, b = map(int, input().split())
i = 2
flag = True
while True:
    if i*i >= n: break
    if n % i == 0:
        flag = False
        break
    i += 1
if flag:
    i = 2
    n += b*1_000_000
    while True:
        if i*i >= n: break
        if n % i == 0:
            flag = False
            break
        i += 1
if flag: print("Yes")
else: print("No")
