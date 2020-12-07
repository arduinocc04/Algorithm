import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a = input().rstrip()
    cnt = 0
    flag = True
    for i in a:
        if i == '(':
            cnt += 1
        else:
            if cnt != 0:
                cnt -= 1
            else:
                flag = False
                break
    if cnt != 0:
        flag = False
    
    if flag:  print('YES')
    else:  print('NO')