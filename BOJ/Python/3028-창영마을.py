b = [1, 2, 3]
for i in input():
    if i == 'A':
        tmp = b[0]
        b[0]  = b[1]
        b[1] = tmp
    elif i == 'B':
        tmp = b[1]
        b[1] = b[2]
        b[2] = tmp
    elif i == 'C':
        tmp = b[2]
        b[2] = b[0]
        b[0] = tmp
print(b.index(1)+1)
