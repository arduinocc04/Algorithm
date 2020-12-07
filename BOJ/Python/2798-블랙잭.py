maxVal = int(input().split()[1])
cardList = [int(i) for i in input().split()]

val = 0

for i in range(len(cardList)):
    for k in range(len(cardList)):
        for j in range(len(cardList)):
            if i != k and k != j and j != i:
                a = cardList[i] + cardList[j] + cardList[k]
                if a<= maxVal and val <a:
                    val = a
print(val)
