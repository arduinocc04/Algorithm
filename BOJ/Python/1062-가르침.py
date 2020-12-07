def calc(n=532741,cnt=5, i=0):
    global res
    if cnt == k:
        res.append(n)
        return
    if i > 25:
        return
    if not i in [19,13,8,2,0]:
        calc((n|(1<<i))|532741,cnt+1,i+1)
    calc(n, cnt,i+1)
def calc2(n=67108863,cnt=0, i=0):
    global res
    if cnt == 26-k:
        res.append(n)
        return
    if i > 25:
        return
    if not i in [19,13,8,2,0]:
        calc2(n^(1<<i),cnt+1,i+1)
    calc2(n, cnt,i+1)
n,k = map(int, input().split())
words = [input() for i in range(n)]
for i in range(len(words)):
    tmp = 0
    for c in words[i]:
        tmp |= (1<<ord(c)-97)
    words[i] = tmp
if k < 5:
    print(0)
else:
    max_ = 0
    res = []
    if k > 13:
        calc2()
    else:
        calc()
    for std in res:
        cnt = 0
        for i in range(len(words)):
            if words[i]&std == words[i]:
                cnt += 1
        if max_ < cnt:
            max_ = cnt
    print(max_)