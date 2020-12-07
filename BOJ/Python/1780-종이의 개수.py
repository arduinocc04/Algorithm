n = int(input())
map_ = []
for i in range(n):
    map_.append([int(i) for i in input().split()])

cnt = [0, 0, 0]#0, 1, -1

def calc(xStart, xFinish, yStart, yFinish):
    global cnt
    paper = map_[yStart:yFinish]
    for i in range(len(paper)):
        paper[i] = paper[i][xStart:xFinish]
    a = paper[0][0]
    flag = True
    for oneLine in paper:
        for character in oneLine:
            if character != a:
                flag = False
                break
        if not flag:
            break
    if flag:
        cnt[a] += 1
    else:
        a = len(paper)//3
        calc(xStart, xStart + a, yStart, yStart + a)
        calc(xStart + a, xStart + 2*a, yStart, yStart + a)
        calc(xStart + 2*a, xStart + len(paper), yStart, yStart + a)
        calc(xStart, xStart + a, yStart + a, yStart + 2*a)
        calc(xStart + a, xStart + 2*a, yStart + a, yStart + 2*a)
        calc(xStart + 2*a, xStart + len(paper), yStart + a, yStart + 2*a)
        calc(xStart, xStart + a, yStart + 2*a, yStart + len(paper))
        calc(xStart + a, xStart + 2*a, yStart + 2*a, yStart + len(paper))
        calc(xStart + 2*a, xStart + len(paper), yStart + 2*a, yStart + len(paper))

calc(0, n, 0, n)
print(cnt[-1])
print(cnt[0])
print(cnt[1])