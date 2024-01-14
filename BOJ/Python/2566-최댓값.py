maxIn = (0, 0)
a = [[int(i) for i in input().split()] for _ in range(9)]
for i in range(9):
    for j in range(9):
        if a[i][j] > a[maxIn[0]][maxIn[1]]:
            maxIn = i, j
print(a[maxIn[0]][maxIn[1]])
print(maxIn[0] + 1, maxIn[1] + 1)
