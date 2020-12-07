h,w = map(int, input().split())
map_ = []
visited = [[False]*w for _ in range(w)]
for _ in range(h):
    map_.append([i for i in input()])

dx,dy = [-1, 1, 0, 0], [0, 0, -1, 1]
max_ = 0
def dfs(x=0,y=0,n=map_[0][0]):
    global max_
    for i in range(4):
        tmpX = x + dx[i]
        tmpY = y + dy[i]
        if 0 <= tmpX <= h - 1 and 0 <= tmpY <= w -1 and not map_[tmpX][tmpY] in n:
            dfs(tmpX, tmpY, n+map_[tmpX][tmpY])
        else:
            if max_ < len(n):
                max_ = len(n)
dfs()
print(max_)