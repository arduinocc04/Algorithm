n, p = map(int, input().split())
history = [n]
while True:
    t = (history[-1]*n) % p
    flag = False
    for i in range(len(history)):
        if history[-i - 1] == t:
            flag = True
            print(i + 1)
            break
    if flag: break
    history.append(t)
