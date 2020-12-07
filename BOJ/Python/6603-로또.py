def calc(a = [], prev = -1):
    if len(a) == 6:
        res = ''
        for i in a:
            res += str(i) + ' '
        print(res[:-1])
        return
    else:
        for i in range(prev+1, len(s),1):
            calc(a + [s[i]], i)
while True:
    s = [int(i) for i in input().split()]
    k = s.pop(0)
    if k == 0:
        break
    calc()
    print()