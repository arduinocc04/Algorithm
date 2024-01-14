for _ in range(int(input()):
    ans = int(input())
    for i in range(int(input())):
        x, y = map(int, input().split())
        ans += x*y
    print(ans)
