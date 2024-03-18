a = "abcdefghijklmnopqrstuvwxyz"
A = a.upper()

for i in input():
    for j in i:
        if j in a:
            print(a[(a.find(j) + 13)%len(a)], end='')
        elif j in A:
            print(A[(A.find(j) + 13)%len(a)], end='')
        else:
            print(j, end = '')
