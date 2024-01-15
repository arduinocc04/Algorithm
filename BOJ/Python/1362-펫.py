i = 1
while True:
    o, w = map(int, input().split())
    if o == w == 0: break
    now_weight = w
    dead = False
    while True:
        if now_weight <= 0:
            dead = True

        a, b = input().split()
        if a == '#': break
        b = int(b)
        if a == 'E':
            now_weight -= b
        else: now_weight += b
        if now_weight <= 0:
            dead = True
    print(i, end =' ')
    if dead: print("RIP")
    else:
        if o/2 < now_weight < 2*o:
            print(":-)")
        else: print(":-(")
    i += 1
