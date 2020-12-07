import sys
cnt = int(input())
if cnt != 0:
    opinions = []
    for i in range(cnt):
        opinions.append(int(sys.stdin.readline()))

    toDel = round(cnt*0.15)

    opinions.sort()
    if toDel != 0:
        opinions = opinions[toDel:-toDel]
    print(round(sum(opinions)/len(opinions)))

else:
    print(0)
