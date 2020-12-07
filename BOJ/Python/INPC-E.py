content = input()
space = int(input())
alphas = [int(i) for i in input().split()]
title = ''
for i in content.split():
    title += i[0]
prev = ''
flag = True
for i in content:
    if prev == i: continue
    if ord(i) >= 97:
        alphas[ord(i)-97] -= 1
        if alphas[ord(i)-97] < 0:
            flag = False
            break
    elif ord(i) > 32:
        alphas[ord(i) - 65] -= 1
        if alphas[ord(i) - 65] < 0:
            flag = False
            break
    else:
        space -= 1
        if space < 0:
            flag = False
            break
    prev = i
if flag:
    prev = ''
    for i in title:
        if prev == i: continue
        if ord(i) >= 97:
            alphas[ord(i)-97] -= 1
            if alphas[ord(i)-97] < 0:
                flag = False
                break
        elif ord(i) > 32:
            alphas[ord(i) - 65] -= 1
            if alphas[ord(i) - 65] < 0:
                flag = False
                break
        else:
            space -= 1
            if space < 0:
                flag = False
                break
        prev = i
    if flag:
        print(title.upper())
    else:
        print('-1')
else:
    print(-1)