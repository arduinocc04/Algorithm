n = []
while True:
    text = input()
    if text == '고무오리 디버깅 끝':  break
    if text == '문제':
        n.append(False)
    elif text == '고무오리':
        flag = False
        for i in range(len(n)):
            if not n[i]:
                n[i] = True
                flag = True
                break
        if not flag:
            n.append(False)
            n.append(False)
if n.count(False) > 0:
    print('힝구')
else:
    print('고무오리야 사랑해')