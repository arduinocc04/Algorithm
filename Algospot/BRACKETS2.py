#BRACKETS2
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    stack = []
    n = input().rstrip()
    flag = True
    for i in n:
        if i == '{': stack.append(i)
        elif i == '(': stack.append(i)
        elif i == '[': stack.append(i)
        else:
            if len(stack) == 0:
                flag = False
                break
            elif i == ')':
                if stack.pop() != '(':
                    flag = False
                    break
            elif i == '}':
                if stack.pop() != '{':
                    flag = False
                    break
            else:
                if stack.pop() != '[':
                    flag = False
                    break
    if len(stack) > 0: flag = False
    if flag: print('YES')
    else: print('NO')