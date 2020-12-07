n = int(input())
def calc(stack=[]):
    global cnt
    if len(stack) == n:
        cnt += 1
        return
    for i in range(n):
        if i in stack:
            continue

        flag = False
        for j in range(len(stack)):
            if j+1 == abs(stack[-j-1]-i):
                flag = True
                break
        if flag:
            continue
        calc(stack+[i])
cnt = 0
calc()
print(cnt)