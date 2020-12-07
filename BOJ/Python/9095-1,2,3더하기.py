def calc(n:int) -> None:
    global cnt 
    if n == a:
        cnt += 1
        return
    elif n > a:
        return
    else:
        calc(n+1)
        calc(n+2)
        calc(n+3)
for _ in range(int(input())):
    a = int(input())
    cnt = 0
    calc(0)
    print(cnt)