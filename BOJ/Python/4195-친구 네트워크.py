import sys
input = sys.stdin.readline
def getParent(n):
    global cnt
    if p[n] == n:  return n
    p[n] = getParent(p[n])
    return p[n]
def union(n1,n2):
    global p, cnt
    p1 = getParent(n1)
    p2 = getParent(n2)
    
    if p1>p2:
        p[p1] = p2
        cnt[p2] += cnt[p1]
        cnt[p1] = 0
    else:
        p[p2] = p1
        cnt[p1] += cnt[p2]
        cnt[p2] = 0
def isInSameSet(n1,n2):
    return getParent(n1) == getParent(n2)
for _ in range(int(input())):
    f = int(input())
    p = [i for i in range(2*f)]
    cnt = [1]*(f*2)
    dict_ = {}
    last = -1
    for i in range(f):
        a,b = input().split()
        if a in dict_:
            a = dict_[a]
        else:
            dict_[a] = last+1
            last += 1
            a = last
        if b in dict_:
            b = dict_[b]
        else:
            dict_[b] = last+1
            last += 1
            b = last
        if not isInSameSet(a,b):
            sys.stdout.write(str(cnt[getParent(a)] + cnt[getParent(b)]) + '\n')
            union(a,b)
        else:
            sys.stdout.write(str(cnt[getParent(a)]) + '\n')