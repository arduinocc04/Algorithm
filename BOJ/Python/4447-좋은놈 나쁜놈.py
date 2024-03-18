for _ in range(int(input())):
    hero = input()
    g = hero.lower().count('g')
    b = hero.lower().count('b')
    print(hero, end = ' is ')
    if g > b:
        print("GOOD")
    elif g < b:
        print("A BADDY")
    else: print("NEUTRAL")
