import sys
a = sys.stdin.readlines()
cnt = [0]*30
for i in a:
    for a in i.strip():
        if a == ' ': continue
        cnt[ord(a) - ord('a')] += 1

maxVal = cnt[0]
maxIs = [0]

for i in range(1, 30):
    if cnt[i] > maxVal:
        maxVal = cnt[i]
        maxIs = [i]
    elif cnt[i] == maxVal:
        maxIs.append(i)
for i in maxIs:
    print(chr(i + ord('a')), end='')
