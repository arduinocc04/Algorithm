n = int(input())
m = int(input())
def find(n):
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]
def union(n1,n2):
    if n1>n2:
        p[n1] = n2
    else:
        p[n2] = n1
def isInSameSet(n1,n2):
    return find(n1) == find(n2)
p = [i for i in range(n)]
for i in range(n):
    tmp = [int(k) for k in input().split()]
    for j in range(n):
        if tmp[j]:
            union(i,j)
a = [int(i)-1 for i in input().split()]
flag = True
for i in range(len(a)):
    if not isInSameSet(a[0], a[i]):
        flag = False
        break
if flag:
    print('YES')
else:
    print('NO')