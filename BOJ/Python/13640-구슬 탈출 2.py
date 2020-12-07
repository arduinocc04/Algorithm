from collections import deque
n,m = map(int, input().split())
map_ = []
for i in range(n):
    tmp = input()
    tmp2 = []
    for j in range(m):
        if tmp[j] == 'R':
            red = (i,j)
            tmp2.append('.')
        elif tmp[j] == 'B':
            blue = (i,j)
            tmp2.append('.')
        else:
            tmp2.append(tmp[j])
    map_.append(tmp2)

flag = False
rQueue