for _ in range(int(input())):
    m = 987654321
    n = int(input())
    a = [int(i) for i in input().split()]
    for cand in range(100):
        s = 0
        for x in a:
            s += abs(cand - x)
        m = min(m, s)
    print(m)
