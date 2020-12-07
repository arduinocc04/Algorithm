import sys
input = sys.stdin.readline
stack = []
while True:
    string = input().rstrip()
    if string == '.': break
    stack.clear()
    flag = True
    for i in string:
        if i == '(':
            stack.append(i)
        elif i == '[':
            stack.append(i)
        elif i == ')':
            if len(stack) == 0 or (stack.pop() != '('):
                flag = False
                break
        elif i == ']':
            if len(stack) == 0 or (stack.pop() != '['):
                flag = False
                break
    if len(stack) != 0: flag = False
    if flag: print("yes")
    else: print('no')