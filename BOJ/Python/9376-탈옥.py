for _ in range(int(input())):
    h,w = map(int, input().split())
    map_ = []
    starts = []
    visited = []
    for i in range(h):
        tmp = input()
        tmp2 = []
        for j in range(w):
            if tmp[j] == '$':
                starts.append((i,j))
                tmp2.append('.')
            else:
                tmp2.append(tmp[j])
        map_.append(tmp2)
