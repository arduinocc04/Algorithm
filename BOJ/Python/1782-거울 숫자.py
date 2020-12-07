a,b = map(int, input().split())
cnt = 0
visited = set()
def calc(n:int) -> None:
    global cnt, visited
    if n > b or n in visited:
        return
    else:
        cnt += 1
        for i in [1,8,0]:
            a = int(str(n) + str(i))
            visited.add(a)
            calc(a)
        for i in [25,52]:
            a = int(str(n) + str(i))
            visited.add(a)
            calc(a)
calc()
print(cnt)