n,m = map(int, input().split())
map_ = [[int(i) for i in input().split()] for _ in range(n)]
houses = []
chickens = []
for i in range(n):
    for j in range(n):
        if map_[i][j] == 1:
            houses.append((i,j))
        elif map_[i][j] == 2:
            chickens.append((i,j))
list_= []
def calc(n=[], prev=-1):
    global list_
    if len(n) == m:
        list_.append(n)
        return
    elif prev == len(chickens)-1:  return
    for i in range(prev, len(chickens), 1):
        calc(n + [chickens[i]], i+1)
def getDist(x1,y1,x2,y2):  return abs(x1-x2) + abs(y1-y2)
min_ = 123323
calc()
for i in range(len(list_)):
    s = 0
    for h in houses:
        tmp = 122333
        for c in list_[i]:
            tmp = min(tmp, getDist(h[0], h[1], c[0], c[1]))
        s += tmp
    if min_ > s:
        min_ = s
print(min_)