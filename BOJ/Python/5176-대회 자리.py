for _ in range(int(input())):
    p, m = map(int, input().split())
    used = [False]*510
    cnt = 0
    for i in range(p):
        t = int(input())
        if not used[t]:
            used[t] = True
        else:
            cnt += 1
    print(cnt)
