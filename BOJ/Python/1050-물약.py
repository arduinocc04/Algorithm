import sys

def calc(name:str, cnt:int, fromNames=set()) -> int:
    if not name in indexes:
        return 'N'

    fromNames.add(name)
    minVal = 'N'
    for potionIndex in indexes[name]:
        res = 0
        pIngredients = potions[potionIndex]
        
        for ing, ingCnt in pIngredients:
            if ing in ingredients:
                res += ingCnt*cnt*ingredients[ing]
            else:
                if ing in indexes:
                    if (ing == name) or (ing in fromNames and len(indexes[ing]) == 1):
                        a = 'N'
                    else:
                        a = calc(ing, ingCnt*cnt, fromNames)
                    if a == 'N':
                        res = 'N'
                        break
                    else:
                        res += a
                else:
                    res = 'N'
                    break
        if res != 'N':
            if minVal == 'N' or minVal > res:
                minVal = res
    return minVal
        
potions = []
ingredients = {}
indexes = {}

n, m = map(int, sys.stdin.readline().split())
for _ in range(n):
    name, price = sys.stdin.readline().split()
    ingredients[name] = int(price)

for l in range(m):
    name, recipe = sys.stdin.readline().split('=')
    recipe = recipe.split('+')
    if recipe[-1][-1] == '\n':
        recipe[-1] = recipe[-1][:-1]
    for i in range(len(recipe)):
        recipe[i] = [recipe[i][1:], int(recipe[i][0])]

    recipe.sort(key=lambda x:x[0])
    delList = []
    for i in range(len(recipe)-1):
        if recipe[-i-1][0] == recipe[-i-2][0]:
            recipe[-i-2][1] += recipe[-i-1][1]
            delList.append(-i-1)
    for i in range(len(delList)):
        del recipe[delList[i]+i]

    potions.append(recipe)

    if name in indexes:
        indexes[name].append(l)
    else:
        indexes[name] = [l]

price = calc('LOVE', 1)
if price != 'N':
    if price > 1000000000:
        print(1000000001)
    else:
        print(price)
else:
    print(-1)