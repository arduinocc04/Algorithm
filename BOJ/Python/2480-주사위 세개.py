dices = [int(i) for i in input().split()]

if dices[0] == dices[1] and dices[0] == dices[2]:
    print(10000+dices[0]*1000)
else:
    flag = False
    for i in range(3):
        if dices[i] == dices[i-1]:
            flag = dices[i]
    if flag:
        print(1000 + flag*100)
    else:
        print(max(dices)*100)
