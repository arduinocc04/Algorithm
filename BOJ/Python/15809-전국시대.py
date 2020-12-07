import sys
input = sys.stdin.readline
n,m = map(int, input().split())
a = [int(input()) for _ in range(n)]
p = [i for i in range(n)]

def find(n):
    if p[n] == n:  return n
    p[n] = find(p[n])
    return p[n]

def war(n1,n2):
    global p
    n1 = find(n1)
    n2 = find(n2)
    if a[n1] > a[n2]:
        a[n1] -= a[n2]
        a[n2] = 0
        p[n2] = n1
    elif a[n1] == a[n2]:
        a[n1] = 0
        a[n2] = 0
        p[n2] = -1
        p[n1] = -1
    else:
        a[n2] -= a[n1]
        p[n1] = n2
        a[n1] = 0

def union(n1, n2):
    global p, a
    n1 = find(n1)
    n2 = find(n2)
    """
    if a[n1] < a[n2]:
        a[n2] += a[n1]
        a[n1] = 0
        p[n1] = n2
    else:
        a[n1] += a[n2]
        a[n2] = 0
        p[n2] = n1
    """
    if n1 < n2:
        p[n2] = n1
        a[n1] += a[n2]
        a[n2] = 0
    else:
        p[n1] = n2
        a[n2] += a[n1]
        a[n1] = 0

for _ in range(m):
    o, p2, q = map(int, input().split())
    if o == 1:
        union(p2-1,q-1)
    else:
        war(p2-1,q-1)

tmp = []
for i in a:
    if i > 0:
        tmp.append(i)
tmp.sort()
print(len(tmp))
for i in range(len(tmp)):
    print(tmp[i], end=' ')