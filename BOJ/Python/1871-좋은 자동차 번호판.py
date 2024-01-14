 for _ in range(int(input())):
    a, b = input().split('-')
    ansA = 0
    t = 1
    for i in a[::-1]:
        ansA += (ord(i) - ord('A'))*t
        t *= 26
    if abs(ansA - int(b)) <= 100:
        print("nice")
    else: print("not nice")
