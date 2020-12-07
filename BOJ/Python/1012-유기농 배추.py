def find(x,y):
    global delList
    if [x,y] in dotList:
        for i in range(len(dotList)):
            if dotList[i] == [x,y]:
                delList.append(i)
                break
        return find(x-1,y)*find(x+1,y)*find(x,y-1)*find(x,y+1)
    else:
        return 0
for _ in range(int(input())):
    m,n,k = map(int, input().split())
    count =0
    dotList = []
    for i in range(k):
        dotList.append([int(j) for j in input().split()])
    while len(dotList) != 0:
        delList = []
        find(dotList[0][0], dotList[0][1])
        for i in range(len(delList)):
            del dotList[delList[i]-i]
        delList = []
        count += 1
    print(count)
        