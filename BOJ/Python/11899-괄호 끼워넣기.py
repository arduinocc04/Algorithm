def calc(a:str) -> None:
    global cnt
    start = 0
    finish = len(a)-1
    while a[start] != '(':
        start += 1
        if start == len(a):
            cnt += 1
            return 
    while a[finish] != ')':
        finish -= 1
        if finish == -1:
            cnt += 1
            return 
    return calc(a[start:finish+1])

a = input()
flag = False
cnt = 0
calc(a)
print(len(a)-cnt*2)