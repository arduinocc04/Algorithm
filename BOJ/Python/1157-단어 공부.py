cnt = [0]*26
for c in input():
    c = ord(c)
    if c > 90:
        c -= 32
    c -= 65
    cnt[c] += 1
    
flag = False
max_ = 0
for i in range(len(cnt)):
    if cnt[i] > cnt[max_]:
        flag = False
        max_ = i
    elif cnt[i] == cnt[max_] and i != max_:
        flag = True
if flag:
    print('?')
else:
    print(chr(max_+65))