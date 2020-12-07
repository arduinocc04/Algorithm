h,w = map(int, input().split())
def getHaveToReplaceCnt(mp, reverse = 0):
    if not reverse:
        a = getHaveToReplaceCnt(mp, 1)
    cnt = 0
    for i in range(8):
        for j in range(8):
            if mp[i][j] ^ (j+reverse+i)%2:#&((j+int(reverse))%2):
                cnt += 1
    if reverse:
        return cnt
    else:
        return min(cnt, a)

def getMap(sX,sY):
    return [map_[i][sX:sX+8] for i in range(sY, sY+8)]
            
map_ = []
for _ in range(h):
    a = input()
    tmp = []
    for i in a:
        if i == 'W':
            tmp.append(True)
        else:
            tmp.append(False)
    map_.append(tmp)

res = []
for i in range(h-7):
    for j in range(w-7):
        res.append(getHaveToReplaceCnt(getMap(j, i)))

print(min(res))