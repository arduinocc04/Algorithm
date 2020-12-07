import sys
sys.setrecursionlimit(1000000)
def calc(x, y):
    global delList, visited
    if x >= mapWidth or x < 0 or y >= mapHeight or y < 0 or visited[x][y]:
        return False

    visited[x][y] = True
    flag = False
    for i in range(len(map_)):
        if map_[i] == [x,y]:
            delList.append(i)
            flag = True
            break
        
    if flag:
        calc(x+1, y)
        calc(x-1, y)
        calc(x, y+1)
        calc(x, y-1)
        calc(x-1, y+1)
        calc(x-1, y-1)
        calc(x+1, y+1)
        calc(x+1, y-1)
    else:
        return False


while True:
    mapWidth, mapHeight = map(int, input().split())
    if mapWidth == mapHeight == 0:
        break
    map_ = list()
    visited = []
    for _ in range(mapWidth):
        visited.append([False]*mapHeight)
    delList = []
    for k in range(mapHeight):
        a = [int(i) for i in input().split()]
        for j in range(len(a)):
            if a[j] == 1:
                map_.append([j, k])
    cnt = 0
    while len(map_):
        calc(map_[0][0], map_[0][1])
        delList.sort(reverse=True)
        for i in delList:
            del map_[i]
        delList = []
        cnt += 1
    print(cnt)