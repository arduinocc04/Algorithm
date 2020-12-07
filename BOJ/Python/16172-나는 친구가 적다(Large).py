string = input()
keyword = input()
cnt = 0
flag = 0
posIns = []
for i in range(len(string)):
    if not 48 <= ord(string[i]) <= 57:#숫자가 아닐때
        if string[i] == keyword[0]:#keyword에 속하면
            posIns.append(i)

out = False
dels = []
for i in range(len(posIns)-1):
    if posIns[i] - posIns[i+1] < len(keyword):
        dels.append(i)
for j in range(len(posIns)):
    if out:
        break
    cnt = 0
    for i in range(posIns[j], len(string)):
        if not 48 <= ord(string[i]) <= 57:#숫자가 아닐때
            if string[i] == keyword[cnt]:#keyword에 속하면
                cnt += 1
                if cnt == len(keyword):
                    flag = 1
                    out = True
                    break
            else:#없으면 초기화
                break
print(flag)