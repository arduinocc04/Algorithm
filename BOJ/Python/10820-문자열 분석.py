import sys
for s in sys.stdin.readlines():
    s = s.replace('\n', '')
    cnt = [0]*4
    for i in s:
        if ord('a') <= ord(i) <= ord('z'):
            cnt[0] += 1
        elif ord('A') <= ord(i) <= ord('Z'):
            cnt[1] += 1
        elif ord('0') <= ord(i) <= ord('9'):
            cnt[2] += 1
        else: cnt[3] += 1
    print(*cnt)
